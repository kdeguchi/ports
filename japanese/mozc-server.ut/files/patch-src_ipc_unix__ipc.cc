--- src/ipc/unix_ipc.cc.orig	2022-07-23 14:02:59 UTC
+++ src/ipc/unix_ipc.cc
@@ -40,6 +40,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+#include <sys/ucred.h>
+#endif
 #include <sys/wait.h>
 #include <unistd.h>
 
@@ -125,6 +128,28 @@ bool IsWriteTimeout(int socket, int timeout) {
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+  // If the OS is MAC, we should validate the peer by using LOCAL_PEERCRED.
+  struct xucred peer_cred;
+  socklen_t peer_cred_len = sizeof(struct xucred);
+  if (::getsockopt(socket, 0, LOCAL_PEERCRED,
+                   &peer_cred, &peer_cred_len) < 0) {
+    LOG(ERROR) << "cannot get peer credential.  NOT a Unix socket?";
+    return false;
+  }
+  if (peer_cred.cr_version != XUCRED_VERSION) {
+    LOG(WARNING) << "credential version mismatch.";
+    return false;
+  }
+  if (peer_cred.cr_uid != ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_cred.cr_uid << "!=" << ::geteuid();
+    return false;
+  }
+  // MacOS doesn't have cr_pid;
+  *pid = 0;
+#endif
+
+#if defined(OS_LINUX) && !defined(OS_FREEBSD)
   // On ARM Linux, we do nothing and just return true since the platform
   // sometimes doesn't support the getsockopt(sock, SOL_SOCKET, SO_PEERCRED)
   // system call.
@@ -146,6 +171,7 @@ bool IsPeerValid(int socket, pid_t *pid) {
 
   *pid = peer_cred.pid;
 #endif  // __arm__
+#endif
 
   return true;
 }
@@ -278,7 +304,12 @@ void IPCClient::Init(const std::string &name, const st
     address.sun_family = AF_UNIX;
     ::memcpy(address.sun_path, server_address.data(), server_address_length);
     address.sun_path[server_address_length] = '\0';
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+    address.sun_len = SUN_LEN(&address);
+    const size_t sun_len = sizeof(address);
+#else
     const size_t sun_len = sizeof(address.sun_family) + server_address_length;
+#endif
     pid_t pid = 0;
     if (::connect(socket_, reinterpret_cast<const sockaddr *>(&address),
                   sun_len) != 0 ||
@@ -390,7 +421,12 @@ IPCServer::IPCServer(const std::string &name, int32_t 
   int on = 1;
   ::setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&on),
                sizeof(on));
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+  addr.sun_len = SUN_LEN(&addr);
+  const size_t sun_len = sizeof(addr);
+#else
   const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
+#endif
   if (is_file_socket) {
     // Linux does not use files for IPC.
     ::chmod(server_address_.c_str(), 0600);

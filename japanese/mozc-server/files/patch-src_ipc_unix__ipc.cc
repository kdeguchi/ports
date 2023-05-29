--- src/ipc/unix_ipc.cc.orig	2023-05-27 07:35:04 UTC
+++ src/ipc/unix_ipc.cc
@@ -37,6 +37,9 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/un.h>
+#if defined(__APPLE__) || defined(__FreeBSD__)
+#include <sys/ucred.h>
+#endif
 #include <unistd.h>
 
 #include <cerrno>
@@ -120,7 +123,28 @@ bool IsWriteTimeout(int socket, absl::Duration timeout
 
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
+#if defined(__APPLE__) || defined(__FreeBSD__)
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
 
+#if defined(__linux__) && !defined(__FreeBSD__)
   struct ucred peer_cred;
   int peer_cred_len = sizeof(peer_cred);
   if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED,
@@ -136,6 +160,7 @@ bool IsPeerValid(int socket, pid_t *pid) {
   }
 
   *pid = peer_cred.pid;
+#endif
 
   return true;
 }
@@ -267,7 +292,12 @@ void IPCClient::Init(const absl::string_view name,
     address.sun_family = AF_UNIX;
     ::memcpy(address.sun_path, server_address.data(), server_address_length);
     address.sun_path[server_address_length] = '\0';
+#if defined(__APPLE__) || defined(__FreeBSD__)
+    address.sun_len = SUN_LEN(&address);
+    const size_t sun_len = sizeof(address);
+#else
     const size_t sun_len = sizeof(address.sun_family) + server_address_length;
+#endif
     pid_t pid = 0;
     if (::connect(socket_, reinterpret_cast<const sockaddr *>(&address),
                   sun_len) != 0 ||
@@ -378,7 +408,12 @@ IPCServer::IPCServer(const std::string &name, int32_t 
   int on = 1;
   ::setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&on),
                sizeof(on));
+#if defined(__APPLE__) || defined(__FreeBSD__)
+  addr.sun_len = SUN_LEN(&addr);
+  const size_t sun_len = sizeof(addr);
+#else
   const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
+#endif
   if (is_file_socket) {
     // Linux does not use files for IPC.
     ::chmod(server_address_.c_str(), 0600);

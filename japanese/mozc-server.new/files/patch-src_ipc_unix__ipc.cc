--- src/ipc/unix_ipc.cc.orig	2022-07-23 14:02:59 UTC
+++ src/ipc/unix_ipc.cc
@@ -41,6 +41,7 @@
 #include <sys/types.h>
 #include <sys/un.h>
 #include <sys/wait.h>
+#include <sys/ucred.h>
 #include <unistd.h>
 
 #include <cerrno>
@@ -125,27 +126,25 @@ bool IsWriteTimeout(int socket, int timeout) {
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
-  // On ARM Linux, we do nothing and just return true since the platform
-  // sometimes doesn't support the getsockopt(sock, SOL_SOCKET, SO_PEERCRED)
-  // system call.
-  // TODO(yusukes): Add implementation for ARM Linux.
-#ifndef __arm__
-  struct ucred peer_cred;
-  int peer_cred_len = sizeof(peer_cred);
-  if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED,
-                 reinterpret_cast<void *>(&peer_cred),
-                 reinterpret_cast<socklen_t *>(&peer_cred_len)) < 0) {
-    LOG(ERROR) << "cannot get peer credential. Not a Unix socket?";
+  // If the OS is MAC, we should validate the peer by using LOCAL_PEERCRED.
+  struct xucred peer_cred;
+  socklen_t peer_cred_len = sizeof(struct xucred);
+  if (::getsockopt(socket, 0, LOCAL_PEERCRED,
+                   &peer_cred, &peer_cred_len) < 0) {
+    LOG(ERROR) << "cannot get peer credential.  NOT a Unix socket?";
     return false;
   }
-
-  if (peer_cred.uid != ::geteuid()) {
-    LOG(WARNING) << "uid mismatch." << peer_cred.uid << "!=" << ::geteuid();
+  if (peer_cred.cr_version != XUCRED_VERSION) {
+    LOG(WARNING) << "credential version mismatch.";
     return false;
   }
+  if (peer_cred.cr_uid != ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_cred.cr_uid << "!=" << ::geteuid();
+    return false;
+  }
 
-  *pid = peer_cred.pid;
-#endif  // __arm__
+  // MacOS doesn't have cr_pid;
+  *pid = 0;
 
   return true;
 }
@@ -278,7 +277,8 @@ void IPCClient::Init(const std::string &name, const st
     address.sun_family = AF_UNIX;
     ::memcpy(address.sun_path, server_address.data(), server_address_length);
     address.sun_path[server_address_length] = '\0';
-    const size_t sun_len = sizeof(address.sun_family) + server_address_length;
+    address.sun_len = SUN_LEN(&address);
+    const size_t sun_len = sizeof(address);
     pid_t pid = 0;
     if (::connect(socket_, reinterpret_cast<const sockaddr *>(&address),
                   sun_len) != 0 ||
@@ -390,7 +390,8 @@ IPCServer::IPCServer(const std::string &name, int32_t 
   int on = 1;
   ::setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&on),
                sizeof(on));
-  const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
+  addr.sun_len = SUN_LEN(&addr);
+  const size_t sun_len = sizeof(addr);
   if (is_file_socket) {
     // Linux does not use files for IPC.
     ::chmod(server_address_.c_str(), 0600);

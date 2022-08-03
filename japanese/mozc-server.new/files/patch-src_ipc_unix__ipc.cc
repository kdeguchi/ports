--- src/ipc/unix_ipc.cc.orig	2022-07-23 23:02:59.000000000 +0900
+++ src/ipc/unix_ipc.cc	2022-08-02 16:25:28.797535000 +0900
@@ -125,6 +125,7 @@
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
+#if 0
   // On ARM Linux, we do nothing and just return true since the platform
   // sometimes doesn't support the getsockopt(sock, SOL_SOCKET, SO_PEERCRED)
   // system call.
@@ -146,6 +147,7 @@
 
   *pid = peer_cred.pid;
 #endif  // __arm__
+#endif
 
   return true;
 }

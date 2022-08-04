--- src/ipc/ipc_path_manager.cc.orig	2022-07-23 23:02:59.000000000 +0900
+++ src/ipc/ipc_path_manager.cc	2022-08-04 13:23:50.692134000 +0900
@@ -297,10 +297,12 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WIN
 
+/*
 #ifdef OS_LINUX
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif  // OS_LINUX
+ */
 
   ipc_name->append(ipc_path_info_->key());
   ipc_name->append(".");

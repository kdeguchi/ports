--- src/ipc/ipc_path_manager.cc.orig	2022-07-23 14:02:59 UTC
+++ src/ipc/ipc_path_manager.cc
@@ -297,10 +297,12 @@ bool IPCPathManager::GetPathName(std::string *ipc_name
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

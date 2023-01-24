--- src/ipc/ipc_path_manager.cc.orig	2023-01-23 19:19:19 UTC
+++ src/ipc/ipc_path_manager.cc
@@ -298,10 +298,10 @@ bool IPCPathManager::GetPathName(std::string *ipc_name
   *ipc_name = kIPCPrefix;
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(OS_FREEBSD)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
-#endif  // OS_LINUX
+#endif
 
   ipc_name->append(ipc_path_info_->key());
   ipc_name->append(".");

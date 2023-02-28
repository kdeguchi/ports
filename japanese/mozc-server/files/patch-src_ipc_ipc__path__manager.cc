--- src/ipc/ipc_path_manager.cc.orig	2023-01-23 19:19:19 UTC
+++ src/ipc/ipc_path_manager.cc
@@ -298,10 +298,10 @@ bool IPCPathManager::GetPathName(std::string *ipc_name
   *ipc_name = kIPCPrefix;
 #endif  // _WIN32
 
-#ifdef __linux__
+#ifdef __linux__ && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
-#endif  // __linux__
+#endif
 
   ipc_name->append(ipc_path_info_->key());
   ipc_name->append(".");

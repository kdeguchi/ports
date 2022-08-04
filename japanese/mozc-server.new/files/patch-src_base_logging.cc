--- src/base/logging.cc.orig	2022-07-23 14:02:59 UTC
+++ src/base/logging.cc
@@ -116,7 +116,7 @@ std::string Logging::GetLogMessageHeader() {
 #elif defined(OS_LINUX)
   return absl::StrCat(timestamp, ::getpid(), " ",
                       // It returns unsigned long.
-                      pthread_self());
+                      reinterpret_cast<uint64>(pthread_self()));
 #elif defined(__APPLE__)
 #ifdef __LP64__
   return absl::StrCat(timestamp, ::getpid(), " ",

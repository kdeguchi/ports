--- src/base/logging.cc.orig	2022-07-23 14:02:59 UTC
+++ src/base/logging.cc
@@ -115,8 +115,12 @@ std::string Logging::GetLogMessageHeader() {
                       static_cast<unsigned int>(pthread_self());
 #elif defined(__linux__)
   return absl::StrCat(timestamp, ::getpid(), " ",
+#if defined(__FreeBSD__)
+                      reinterpret_cast<long>(pthread_self()));
+#else
                       // It returns unsigned long.
                       pthread_self());
+#endif
 #elif defined(__APPLE__)
 #ifdef __LP64__
   return absl::StrCat(timestamp, ::getpid(), " ",

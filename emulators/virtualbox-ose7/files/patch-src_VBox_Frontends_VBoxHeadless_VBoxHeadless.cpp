--- src/VBox/Frontends/VBoxHeadless/VBoxHeadless.cpp.orig	2024-10-10 18:30:43 UTC
+++ src/VBox/Frontends/VBoxHeadless/VBoxHeadless.cpp
@@ -61,7 +61,7 @@ using namespace com;
 # include <iprt/process.h>
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS)
 # include <cerrno>
 #endif
 

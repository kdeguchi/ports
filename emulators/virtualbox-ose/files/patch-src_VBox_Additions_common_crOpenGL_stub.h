--- src/VBox/Additions/common/crOpenGL/stub.h.orig	2020-05-14 18:18:51 UTC
+++ src/VBox/Additions/common/crOpenGL/stub.h
@@ -49,7 +49,7 @@
 #include <X11/extensions/Xfixes.h>
 #endif
 
-#if defined(WINDOWS) || defined(Linux) || defined(SunOS)
+#if defined(WINDOWS) || defined(Linux) || defined(FreeBSD) || defined(SunOS)
 # define CR_NEWWINTRACK
 #endif
 

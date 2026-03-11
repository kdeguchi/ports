--- kitty/data-types.h.orig	1979-11-29 15:00:00 UTC
+++ kitty/data-types.h
@@ -23,7 +23,7 @@
 #include "banned.h"
 // Required minimum OpenGL version
 #define OPENGL_REQUIRED_VERSION_MAJOR 3
-#ifdef __APPLE__
+#if defined( __APPLE__) ||defined( __FreeBSD__)
 #include <xlocale.h>
 #define OPENGL_REQUIRED_VERSION_MINOR 3
 #else

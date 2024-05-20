--- glfw/wl_client_side_decorations.c.orig	2024-05-08 04:55:34 UTC
+++ glfw/wl_client_side_decorations.c
@@ -12,6 +12,16 @@
 #include <errno.h>
 #include <string.h>
 #include <stdlib.h>
+// Needed for the BTN_* defines
+#ifdef __has_include
+#if __has_include(<linux/input.h>)
+#include <linux/input.h>
+#elif __has_include(<dev/evdev/input.h>)
+#include <dev/evdev/input.h>
+#endif
+#else
+#include <linux/input.h>
+#endif
 
 #define decs window->wl.decorations
 #define debug debug_rendering

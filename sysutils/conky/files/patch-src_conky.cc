--- src/conky.cc.orig	2024-04-17 19:40:01 UTC
+++ src/conky.cc
@@ -68,6 +68,9 @@
 #ifdef BUILD_IMLIB2
 #include "conky-imlib2.h"
 #endif /* BUILD_IMLIB2 */
+#ifdef BUILD_XSHAPE
+#include <X11/extensions/shape.h>
+#endif /* BUILD_XSHAPE */
 #endif /* BUILD_X11 */
 #ifdef BUILD_NCURSES
 #include <ncurses.h>
@@ -1725,6 +1728,23 @@ void main_loop() {
   sigaddset(&newmask, SIGTERM);
   sigaddset(&newmask, SIGUSR1);
 #endif
+
+#ifdef BUILD_X11
+#ifdef BUILD_XSHAPE
+  /* allow only decorated windows to be given mouse input */
+  int major_version, minor_version;
+  if (!XShapeQueryVersion(display, &major_version, &minor_version)) {
+    NORM_ERR("Input shapes are not supported");
+  } else {
+    if (own_window.get(*state) &&
+        (own_window_type.get(*state) != TYPE_NORMAL ||
+         (TEST_HINT(own_window_hints.get(*state), HINT_UNDECORATED)))) {
+      XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
+         NULL, 0, ShapeSet, Unsorted);
+    }
+  }
+#endif /* BUILD_XSHAPE */
+#endif /* BUILD_X11 */
 
   log_system_details();
 

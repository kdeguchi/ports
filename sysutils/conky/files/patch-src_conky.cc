--- src/conky.cc.orig	2025-06-30 20:36:51 UTC
+++ src/conky.cc
@@ -87,6 +87,9 @@
 #ifdef BUILD_IMLIB2
 #include "conky-imlib2.h"
 #endif /* BUILD_IMLIB2 */
+#ifdef BUILD_XSHAPE
+#include <X11/extensions/shape.h>
+#endif /* BUILD_XSHAPE */
 #endif /* BUILD_X11 */
 
 #ifdef BUILD_NCURSES
@@ -1851,6 +1854,23 @@ void main_loop() {
   sigaddset(&newmask, SIGTERM);
   sigaddset(&newmask, SIGUSR1);
 #endif
+
+#ifdef BUILD_XSHAPE
+    /* allow only decorated windows to be given mouse input */
+    int major_version;
+    int minor_version;
+    if (XShapeQueryVersion(display, &major_version, &minor_version) == 0) {
+      NORM_ERR("Input shapes are not supported");
+    } else {
+      if (own_window.get(*state) &&
+          (own_window_type.get(*state) != window_type::NORMAL ||
+           ((TEST_HINT(own_window_hints.get(*state),
+                       window_hints::UNDECORATED)) != 0))) {
+        XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
+                                nullptr, 0, ShapeSet, Unsorted);
+      }
+    }
+#endif /* BUILD_XSHAPE */
 
   get_system_details();
 

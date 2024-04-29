--- src/conky.cc.orig	2024-04-24 13:56:28 UTC
+++ src/conky.cc
@@ -84,6 +84,12 @@
 #ifdef BUILD_IMLIB2
 #include "conky-imlib2.h"
 #endif /* BUILD_IMLIB2 */
+#ifdef BUILD_XSHAPE
+#include <X11/extensions/shape.h>
+#endif /* BUILD_XSHAPE */
+/* #ifdef BUILD_XFIXES
+#include <X11/extensions/Xfixes.h>
+#endif */ /* BUILD_XFIXES */
 #endif /* BUILD_X11 */
 
 #ifdef BUILD_NCURSES
@@ -1713,6 +1719,34 @@ void main_loop() {
   sigaddset(&newmask, SIGTERM);
   sigaddset(&newmask, SIGUSR1);
 #endif
+
+#ifdef BUILD_XSHAPE
+/* #ifdef BUILD_XFIXES
+      if (own_window_type.get(l) == window_type::UTILITY) {
+        XRectangle rect;
+        XserverRegion region = XFixesCreateRegion(display, &rect, 1);
+        XFixesSetWindowShapeRegion(display, window.window, ShapeInput, 0, 0,
+                                   region);
+        XFixesDestroyRegion(display, region);
+      }
+#endif */ /* BUILD_XFIXES */
+//      if (!wmHint.input) {
+        /* allow only decorated windows to be given mouse input */
+        int major_version;
+        int minor_version;
+        if (XShapeQueryVersion(display, &major_version, &minor_version) == 0) {
+          NORM_ERR("Input shapes are not supported");
+        } else {
+          if (own_window.get(*state) &&
+              (own_window_type.get(*state) != window_type::NORMAL ||
+               ((TEST_HINT(own_window_hints.get(*state),
+                           window_hints::UNDECORATED)) != 0))) {
+            XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
+                                    nullptr, 0, ShapeSet, Unsorted);
+          }
+        }
+//      }
+#endif /* BUILD_XSHAPE */
 
   log_system_details();
 

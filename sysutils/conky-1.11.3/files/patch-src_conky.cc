--- src/conky.cc.orig	2019-03-03 18:24:23 UTC
+++ src/conky.cc
@@ -66,6 +66,9 @@
 #ifdef BUILD_IMLIB2
 #include "imlib2.h"
 #endif /* BUILD_IMLIB2 */
+#ifdef BUILD_XSHAPE
+#include <X11/extensions/shape.h>
+#endif /* BUILD_XSHAPE */
 #endif /* BUILD_X11 */
 #ifdef BUILD_NCURSES
 #include <ncurses.h>
@@ -1859,6 +1862,23 @@ void main_loop() {
   sigaddset(&newmask, SIGTERM);
   sigaddset(&newmask, SIGUSR1);
 #endif
+
+#ifdef BUILD_X11
+#ifdef BUILD_XSHAPE
+	/* allow only decorated windows to be given mouse input */
+	int major_version, minor_version;
+	if (!XShapeQueryVersion(display, &major_version, &minor_version)) {
+		NORM_ERR("Input shapes are not supported");
+	} else {
+		if (own_window.get(*state) &&
+		    (own_window_type.get(*state) != TYPE_NORMAL ||
+		     (TEST_HINT(own_window_hints.get(*state), HINT_UNDECORATED)))) {
+			XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
+			   NULL, 0, ShapeSet, Unsorted);
+		}
+	}
+#endif /* BUILD_XSHAPE */
+#endif /* BUILD_X11 */
 
   last_update_time = 0.0;
   next_update_time = get_time() - fmod(get_time(), active_update_interval());

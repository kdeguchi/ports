--- src/x11.cc.orig	2023-02-18 14:34:53 UTC
+++ src/x11.cc
@@ -55,9 +55,6 @@
 #ifdef BUILD_XINERAMA
 #include <X11/extensions/Xinerama.h>
 #endif
-#ifdef BUILD_XSHAPE
-#include <X11/extensions/shape.h>
-#endif /* BUILD_XSHAPE */
 #ifdef BUILD_XFIXES
 #include <X11/extensions/Xfixes.h>
 #endif /* BUILD_XFIXES */
@@ -620,32 +617,6 @@ void x11_init_window(lua::state &l __attribute__((unus
       wmHint.flags = InputHint | StateHint;
       /* allow decorated windows to be given input focus by WM */
       wmHint.input = TEST_HINT(hints, HINT_UNDECORATED) ? False : True;
-#ifdef BUILD_XSHAPE
-#ifdef BUILD_XFIXES
-      if (own_window_type.get(l) == TYPE_UTILITY) {
-        XRectangle rect;
-        XserverRegion region = XFixesCreateRegion(display, &rect, 1);
-        XFixesSetWindowShapeRegion(display, window.window, ShapeInput, 0, 0, region);
-        XFixesDestroyRegion(display, region);
-      }
-#endif /* BUILD_XFIXES */
-      if (!wmHint.input) {
-        /* allow only decorated windows to be given mouse input */
-        int major_version;
-        int minor_version;
-        if (XShapeQueryVersion(display, &major_version, &minor_version) == 0) {
-          NORM_ERR("Input shapes are not supported");
-        } else {
-          if (own_window.get(*state) &&
-              (own_window_type.get(*state) != TYPE_NORMAL ||
-               ((TEST_HINT(own_window_hints.get(*state), HINT_UNDECORATED)) !=
-                0))) {
-            XShapeCombineRectangles(display, window.window, ShapeInput, 0, 0,
-                                    nullptr, 0, ShapeSet, Unsorted);
-          }
-        }
-      }
-#endif /* BUILD_XSHAPE */
       if (own_window_type.get(l) == TYPE_DOCK ||
           own_window_type.get(l) == TYPE_PANEL) {
         wmHint.initial_state = WithdrawnState;

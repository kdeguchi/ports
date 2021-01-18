--- src/conky.cc.orig
+++ src/conky.cc
@@ -142,6 +142,10 @@
 #ifdef BUILD_BUILTIN_CONFIG
 #include "defconfig.h"
 
+#ifdef BUILD_HSV_GRADIENT
+#include "hsv_gradient.h"
+#endif /* BUILD_HSV_GRADIENT */
+
 namespace {
 const char builtin_config_magic[] = "==builtin==";
 }  // namespace
@@ -1447,8 +1451,13 @@ int draw_each_line_inner(char *s, int special_index, int last_special_applied) {
               unsigned long *tmpcolour = nullptr;
 
               if (current->last_colour != 0 || current->first_colour != 0) {
+#ifdef BUILD_HSV_GRADIENT
+                tmpcolour = do_hsv_gradient(w - 1, current->last_colour,
+                                        current->first_colour);
+#else
                 tmpcolour = do_gradient(w - 1, current->last_colour,
                                         current->first_colour);
+#endif
               }
               colour_idx = 0;
               for (i = w - 2; i > -1; i--) {

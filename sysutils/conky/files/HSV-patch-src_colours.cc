--- src/colours.cc.orig
+++ src/colours.cc
@@ -36,10 +36,10 @@
 #define CONST_8_TO_5_BITS 0.12156862745098
 #define CONST_8_TO_6_BITS 0.247058823529412
 
-static short colour_depth = 0;
-static long redmask, greenmask, bluemask;
+short colour_depth = 0;
+long redmask, greenmask, bluemask;
 
-static void set_up_gradient() {
+void set_up_gradient() {
   int i;
 #ifdef BUILD_X11
   if (out_to_x.get(*state)) {

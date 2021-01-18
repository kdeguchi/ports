--- src/colours.h.orig
+++ src/colours.h
@@ -33,9 +33,15 @@
 
 unsigned int adjust_colours(unsigned int);
 unsigned long *do_gradient(int, unsigned long, unsigned long);
+unsigned long *do_hsv_gradient(int, unsigned long, unsigned long);
 
 long get_x11_color(const std::string &colour);
 // XXX: when everyone uses C++ strings, remove this C version
 long get_x11_color(const char *);
 
+// needed by hsv_gradient
+extern short colour_depth;
+extern long redmask, greenmask, bluemask;
+extern void set_up_gradient();
+
 #endif /* _COLOURS_H */

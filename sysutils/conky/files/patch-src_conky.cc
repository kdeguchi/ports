--- src/conky.cc.orig	2020-07-27 12:01:52 UTC
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
@@ -182,6 +185,8 @@ static conky::simple_config_setting<bool> short_units(
                                                       true);
 static conky::simple_config_setting<bool> format_human_readable(
     "format_human_readable", true, true);
+conky::simple_config_setting<std::string> units_spacer(
+    "units_spacer", "", false);
 
 conky::simple_config_setting<bool> out_to_stdout("out_to_console",
 // Default value is false, unless we are building without X
@@ -587,14 +592,16 @@ void human_readable(long long num, char *buf, int size
   }
   if (short_units.get(*state)) {
     width = 5;
-    format = "%.*f %.1s";
+    format = "%.*f%s%.1s";
   } else {
     width = 7;
-    format = "%.*f %-.3s";
+    format = "%.*f%s%-.3s";
   }
+  width += strlen(units_spacer.get(*state).c_str());
 
   if (llabs(num) < 1000LL) {
     spaced_print(buf, size, format, width, 0, static_cast<float>(num),
+                 units_spacer.get(*state).c_str(),
                  _(*suffix));
     return;
   }
@@ -628,7 +635,9 @@ void human_readable(long long num, char *buf, int size
   if (fnum < 99.95) { precision = 1; /* print 10-99 with one decimal place */ }
   if (fnum < 9.995) { precision = 2; /* print 0-9 with two decimal places */ }
 
-  spaced_print(buf, size, format, width, precision, fnum, _(*suffix));
+  spaced_print(buf, size, format, width, precision, fnum,
+               units_spacer.get(*state).c_str(),
+               _(*suffix));
 }
 
 /* global object list root element */
@@ -736,9 +745,12 @@ void evaluate(const char *text, char *p, int p_max_siz
    * These would require run extract_variable_text_internal() before
    * callbacks and generate_text_internal() after callbacks.
    */
+  /*
   extract_variable_text_internal(&subroot, text);
   conky::run_all_callbacks();
   generate_text_internal(p, p_max_size, subroot);
+  */
+  parse_conky_vars(&subroot, text, p, p_max_size);
   DBGP2("evaluated '%s' to '%s'", text, p);
 
   free_text_objects(&subroot);
@@ -1909,6 +1921,23 @@ void main_loop() {
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

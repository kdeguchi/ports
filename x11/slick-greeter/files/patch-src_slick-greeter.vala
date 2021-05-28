--- src/slick-greeter.vala.orig	2021-02-04 14:56:26 UTC
+++ src/slick-greeter.vala
@@ -703,9 +703,9 @@ public class SlickGreeter
         value = UGSettings.get_string (UGSettings.KEY_FONT_NAME);
         if (value != "")
             settings.set ("gtk-font-name", value, null);
-        var double_value = UGSettings.get_double (UGSettings.KEY_XFT_DPI);
-        if (double_value != 0.0)
-            settings.set ("gtk-xft-dpi", (int) (1024 * double_value), null);
+        var integer_value = UGSettings.get_integer (UGSettings.KEY_XFT_DPI);
+        if (integer_value != 0)
+            settings.set ("gtk-xft-dpi", (int) (1024 * integer_value), null);
         var boolean_value = UGSettings.get_boolean (UGSettings.KEY_XFT_ANTIALIAS);
         settings.set ("gtk-xft-antialias", boolean_value, null);
         value = UGSettings.get_string (UGSettings.KEY_XFT_HINTSTYLE);

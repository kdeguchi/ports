--- src/dash-button.vala.orig	2021-02-04 14:56:26 UTC
+++ src/dash-button.vala
@@ -29,7 +29,7 @@ public class DashButton : FlatButton, Fadable
         set
         {
             _text = value;
-            text_label.set_markup ("<span font=\"Ubuntu 13\">%s</span>".printf (value));
+            text_label.set_markup ("<span font=\"%s\">%s</span>".printf (UGSettings.get_string (UGSettings.KEY_FONT_NAME), value));
         }
     }
 

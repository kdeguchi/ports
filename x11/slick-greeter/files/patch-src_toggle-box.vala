--- src/toggle-box.vala.orig	2021-02-04 14:56:26 UTC
+++ src/toggle-box.vala
@@ -99,7 +99,7 @@ public class ToggleBox : Gtk.Box
         }
 
         var label = new Gtk.Label (null);
-        label.set_markup ("<span font=\"Ubuntu 13\">%s</span>".printf (name));
+        label.set_markup ("<span font=\"%s\">%s</span>".printf (UGSettings.get_string (UGSettings.KEY_FONT_NAME), name));
         label.halign = Gtk.Align.START;
         hbox.pack_start (label, true, true, 0);
 

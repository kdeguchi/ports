--- src/shutdown-dialog.vala.orig	2021-02-04 14:56:26 UTC
+++ src/shutdown-dialog.vala
@@ -104,7 +104,7 @@ public class ShutdownDialog : Gtk.Fixed
         {
             var title_label = new Gtk.Label (_("Shut Down"));
             title_label.visible = true;
-            title_label.override_font (Pango.FontDescription.from_string ("Ubuntu Light 15"));
+            title_label.override_font (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
             title_label.override_color (Gtk.StateFlags.NORMAL, { 1.0f, 1.0f, 1.0f, 1.0f });
             title_label.set_alignment (0.0f, 0.5f);
             vbox.pack_start (title_label, false, false, 0);
@@ -138,7 +138,7 @@ public class ShutdownDialog : Gtk.Fixed
 
         var label = new Gtk.Label (text);
         label.set_line_wrap (true);
-        label.override_font (Pango.FontDescription.from_string ("Ubuntu Light 12"));
+        label.override_font (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
         label.override_color (Gtk.StateFlags.NORMAL, { 1.0f, 1.0f, 1.0f, 1.0f });
         label.set_alignment (0.0f, 0.5f);
         label.visible = true;
@@ -558,7 +558,7 @@ private class DialogButton : Gtk.Button
         if (l != null)
         {
             l.visible = true;
-            l.override_font (Pango.FontDescription.from_string ("Ubuntu Light 12"));
+            l.override_font (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
             l.override_color (Gtk.StateFlags.NORMAL, { 1.0f, 1.0f, 1.0f, 0.0f });
             l.override_color (Gtk.StateFlags.FOCUSED, { 1.0f, 1.0f, 1.0f, 1.0f });
             l.override_color (Gtk.StateFlags.ACTIVE, { 1.0f, 1.0f, 1.0f, 1.0f });

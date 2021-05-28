--- src/prompt-box.vala.orig	2021-02-04 14:56:26 UTC
+++ src/prompt-box.vala
@@ -175,7 +175,7 @@ public class PromptBox : FadableBox
         name_grid.hexpand = true;
 
         name_label = new FadingLabel ("");
-        name_label.override_font (Pango.FontDescription.from_string ("Ubuntu 13"));
+        name_label.override_font (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
         name_label.override_color (Gtk.StateFlags.NORMAL, { 1.0f, 1.0f, 1.0f, 1.0f });
         name_label.valign = Gtk.Align.START;
         name_label.vexpand = true;
@@ -231,7 +231,7 @@ public class PromptBox : FadableBox
         small_name_grid.column_spacing = 4;
 
         small_name_label = new FadingLabel ("");
-        small_name_label.override_font (Pango.FontDescription.from_string ("Ubuntu 13"));
+        small_name_label.override_font (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
         small_name_label.override_color (Gtk.StateFlags.NORMAL, { 1.0f, 1.0f, 1.0f, 1.0f });
         small_name_label.yalign = 0.5f;
         small_name_label.xalign = 0.0f;
@@ -452,7 +452,7 @@ public class PromptBox : FadableBox
     {
         var label = new FadingLabel (text);
 
-        label.override_font (Pango.FontDescription.from_string ("Ubuntu Bold 10"));
+        label.override_font (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
 
         Gdk.RGBA color = { 1.0f, 1.0f, 1.0f, 1.0f };
         if (is_error)

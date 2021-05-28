--- src/dash-entry.vala.orig	2021-02-04 14:56:26 UTC
+++ src/dash-entry.vala
@@ -23,7 +23,7 @@ extern bool gtk_style_context_lookup_color (Gtk.StyleC
 
 public class DashEntry : Gtk.Entry, Fadable
 {
-    public static string font = "Ubuntu 14";
+    public static string font = UGSettings.get_string (UGSettings.KEY_FONT_NAME);
     public signal void respond ();
 
     public string constant_placeholder_text { get; set; }
@@ -153,7 +153,7 @@ public class DashEntry : Gtk.Entry, Fadable
         Gdk.Rectangle rect;
 
         var layout = create_pango_layout (constant_placeholder_text);
-        layout.set_font_description (Pango.FontDescription.from_string ("Ubuntu 13"));
+        layout.set_font_description (Pango.FontDescription.from_string (UGSettings.get_string (UGSettings.KEY_FONT_NAME)));
         layout.get_pixel_size (out layout_width, out layout_height);
 
         get_text_area (out rect);

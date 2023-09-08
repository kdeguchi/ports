--- src/slick-greeter.vala.orig
+++ src/slick-greeter.vala
@@ -714,6 +714,7 @@ public class SlickGreeter
         }
 
         Gtk.init (ref args);
+        Hdy.init();
 
         debug ("Starting slick-greeter %s UID=%d LANG=%s", Config.VERSION, (int) Posix.getuid (), Environment.get_variable ("LANG"));
 

--- src/user-list.vala.orig
+++ src/user-list.vala
@@ -74,7 +74,7 @@ public class UserList : GreeterList
             if (SlickGreeter.singleton.test_mode)
             {
                 if (value)
-                    add_user ("hidden", "Hidden User", null, false, false, null);
+                    add_user ("hidden", "Hidden User", null, null, false, false, null);
                 else
                     remove_entry ("hidden");
                 return;
@@ -840,12 +840,15 @@ public class UserList : GreeterList
         redraw_greeter_box ();
     }
 
-    public void add_user (string name, string label, string? background = null, bool is_active = false, bool has_messages = false, string? session = null)
+    public void add_user (string name, string label, string? avatar = null, string? background = null, bool is_active = false, bool has_messages = false, string? session = null)
     {
         var e = find_entry (name) as UserPromptBox;
         if (e == null)
         {
-            e = new UserPromptBox (name);
+
+            FileIcon avatar_pic = new FileIcon (File.new_for_path (avatar));
+
+            e = new UserPromptBox (name, avatar_pic);
             e.respond.connect (prompt_box_respond_cb);
             e.login.connect (prompt_box_login_cb);
             e.show_options.connect (prompt_box_show_options_cb);
@@ -1024,7 +1027,7 @@ public class UserList : GreeterList
             {
                 debug ("Adding live user account: %s (%s)", username, realname);
 
-                add_user (username, realname, null, true, false, null);
+                add_user (username, realname, null, null, true, false, null);
 
                 // lightdm might add itself to the user list when we do this.
                 remove_entry ("lightdm");
@@ -1061,7 +1064,7 @@ public class UserList : GreeterList
         if (user.real_name == "")
             label = user.name;
 
-        add_user (user.name, label, user.background, user.logged_in, user.has_messages, user.session);
+        add_user (user.name, label, user.image, user.background, user.logged_in, user.has_messages, user.session);
     }
 
     private bool filter_group (string user_name)
@@ -1473,7 +1476,7 @@ public class UserList : GreeterList
             if (test_backgrounds.length () > 0)
                 background = test_backgrounds.nth_data (background_index % test_backgrounds.length ());
         }
-        add_user (e.username, e.real_name, background, e.is_active, e.has_messages, e.session);
+        add_user (e.username, e.real_name, null, background, e.is_active, e.has_messages, e.session);
         n_test_entries++;
 
         return true;

--- src/user-prompt-box.vala.orig
+++ src/user-prompt-box.vala
@@ -29,8 +29,21 @@ public class UserPromptBox : PromptBox
     /* True if should be marked as active */
     public bool is_active;
 
-    public UserPromptBox (string name)
+    protected Hdy.Avatar avatar;
+
+    public UserPromptBox (string name, LoadableIcon avatar_pic)
     {
         Object (id: name);
+
+        //FIXME: Avatar is overlaping clickable userbox space
+        //FIXME: Avatar is not respecting animation
+        //TODO: Make avatar easily disabled from settings
+        avatar = new Hdy.Avatar(42, name, true);
+        if(avatar_pic!=null)
+            avatar.set_loadable_icon(avatar_pic);
+       // avatar.loadable_icon = new FileIcon (avatar_path);
+        avatar.show();
+        name_grid.attach(avatar, -1, 0, 1, 1);
+
     }
 }

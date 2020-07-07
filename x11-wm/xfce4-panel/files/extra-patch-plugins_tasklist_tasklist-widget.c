--- plugins/tasklist/tasklist-widget.c.orig	2019-09-23 22:14:24 UTC
+++ plugins/tasklist/tasklist-widget.c
@@ -2856,6 +2856,11 @@ xfce_tasklist_button_geometry_changed2 (WnckWindow    
       else
         gtk_widget_hide (child->button);
     }
+  /* initiate viewport switch on geometry change - fixes buttons not 
+   * getting updated when using compiz */
+  active_ws = wnck_screen_get_active_workspace (child->tasklist->screen);
+  if (wnck_workspace_is_virtual (active_ws))
+    xfce_tasklist_viewports_changed (child->tasklist->screen, child->tasklist);
 }
 
 

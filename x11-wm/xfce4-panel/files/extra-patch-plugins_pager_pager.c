--- plugins/pager/pager.c.orig	2020-04-29 06:30:30 UTC
+++ plugins/pager/pager.c
@@ -74,6 +74,7 @@ static void     pager_plugin_mode_changed             
 static void     pager_plugin_configure_workspace_settings (GtkWidget         *button);
 static void     pager_plugin_configure_plugin             (XfcePanelPlugin   *panel_plugin);
 static void     pager_plugin_screen_layout_changed        (PagerPlugin       *plugin);
+static void     pager_plugin_get_ratio                    (PagerPlugin       *plugin);
 static void     pager_plugin_get_preferred_width          (GtkWidget           *widget,
                                                            gint                *minimum_width,
                                                            gint                *natural_width);
@@ -328,8 +328,18 @@ pager_plugin_scroll_event (GtkWidget      *widget,
   gint                n_workspaces;
   GdkScrollDirection  scrolling_direction;
 
+  GList         *workspaces;
+  gint          rows, cols;
+  gint          new_x, new_y;
+  gint          workspace_width = 0, workspace_height = 0;
+  gint          screen_width = 0, screen_height = 0;
+  WnckWorkspace *workspace = NULL;
+
   panel_return_val_if_fail (WNCK_IS_SCREEN (plugin->wnck_screen), FALSE);
 
+  workspaces = wnck_screen_get_workspaces (plugin->wnck_screen);
+  n_workspaces = g_list_length (workspaces);
+
   /* leave when scrolling is not enabled */
   if (plugin->scrolling == FALSE)
     return TRUE;
@@ -350,35 +361,85 @@ pager_plugin_scroll_event (GtkWidget      *widget,
       return TRUE;
     }
 
-  active_ws = wnck_screen_get_active_workspace (plugin->wnck_screen);
-  active_n = wnck_workspace_get_number (active_ws);
+  if (G_UNLIKELY (n_workspaces == 1
+    && wnck_workspace_is_virtual (WNCK_WORKSPACE (workspaces->data))))
+  {
+    workspace = wnck_screen_get_active_workspace (plugin->wnck_screen);
 
-  if (scrolling_direction == GDK_SCROLL_UP
-      || scrolling_direction == GDK_SCROLL_LEFT)
-    active_n--;
-  else
-    active_n++;
+    workspace_width = wnck_workspace_get_width (workspace);
+    workspace_height = wnck_workspace_get_height (workspace);
+    screen_width = wnck_screen_get_width (plugin->wnck_screen);
+    screen_height = wnck_screen_get_height (plugin->wnck_screen);
 
-  n_workspaces = wnck_screen_get_workspace_count (plugin->wnck_screen) - 1;
+    cols = workspace_width / screen_width;
+    rows = workspace_height / screen_height;
 
-  if (plugin->wrap_workspaces == TRUE)
-  {
-    /* wrap around */
-    if (active_n < 0)
-      active_n = n_workspaces;
-    else if (active_n > n_workspaces)
-      active_n = 0;
+    new_x = wnck_workspace_get_viewport_x (workspace);
+    new_y = wnck_workspace_get_viewport_y (workspace);
+
+    new_x /= screen_width;
+    new_y /= screen_height;
+
+    if(event->direction == GDK_SCROLL_UP || event->direction == GDK_SCROLL_LEFT) {
+       new_x -= 1;
+    } else {
+       new_x += 1;
+    }
+
+    if(new_x < 0) {
+      if(new_y > 0) {
+        new_y -= 1;
+        new_x = cols - 1;
+      } else {
+        new_x = 0;
+      }
+    }
+
+    if(new_x >= cols) {
+      if(new_y < rows - 1) {
+        new_y += 1;
+        new_x = 0;
+      } else {
+        new_x = cols - 1;
+      }
+    }
+
+    new_x *= screen_width;
+    new_y *= screen_height;
+
+    wnck_screen_move_viewport(plugin->wnck_screen,
+        new_x, new_y);
   }
-  else if (active_n < 0 || active_n > n_workspaces )
-  {
-    /* we do not need to do anything */
-    return TRUE;
-  }
+  else {
+    active_ws = wnck_screen_get_active_workspace (plugin->wnck_screen);
+    active_n = wnck_workspace_get_number (active_ws);
 
-  new_ws = wnck_screen_get_workspace (plugin->wnck_screen, active_n);
-  if (new_ws != NULL && active_ws != new_ws)
-    wnck_workspace_activate (new_ws, event->time);
+    if (scrolling_direction == GDK_SCROLL_UP
+        || scrolling_direction == GDK_SCROLL_LEFT)
+      active_n--;
+    else
+      active_n++;
 
+    n_workspaces = wnck_screen_get_workspace_count (plugin->wnck_screen) - 1;
+
+    if (plugin->wrap_workspaces == TRUE)
+    {
+      /* wrap around */
+      if (active_n < 0)
+        active_n = n_workspaces;
+      else if (active_n > n_workspaces)
+        active_n = 0;
+    }
+    else if (active_n < 0 || active_n > n_workspaces )
+    {
+      /* we do not need to do anything */
+      return TRUE;
+    }
+
+    new_ws = wnck_screen_get_workspace (plugin->wnck_screen, active_n);
+    if (new_ws != NULL && active_ws != new_ws)
+      wnck_workspace_activate (new_ws, event->time);
+  }
   return TRUE;
 }
 
@@ -438,9 +439,6 @@ pager_plugin_screen_layout_changed (PagerPlugin *plugi
         g_message ("Setting the pager rows returned false. Maybe the setting is not applied.");
 
       wnck_pager_set_orientation (WNCK_PAGER (plugin->pager), orientation);
-G_GNUC_BEGIN_IGNORE_DEPRECATIONS
-      plugin->ratio = (gfloat) gdk_screen_width () / (gfloat) gdk_screen_height ();
-G_GNUC_END_IGNORE_DEPRECATIONS
       g_signal_connect_after (G_OBJECT (plugin->pager), "drag-begin",
                               G_CALLBACK (pager_plugin_drag_begin_event), plugin);
       g_signal_connect_after (G_OBJECT (plugin->pager), "drag-end",
@@ -706,6 +702,26 @@ pager_plugin_configure_plugin (XfcePanelPlugin *panel_
 
 
 static void
+pager_plugin_get_ratio (PagerPlugin *plugin)
+{
+  WnckWorkspace *active_ws;
+
+  panel_return_if_fail (XFCE_IS_PAGER_PLUGIN (plugin));
+  panel_return_if_fail (WNCK_IS_SCREEN (plugin->wnck_screen));
+
+  active_ws = wnck_screen_get_active_workspace (plugin->wnck_screen);
+  if (wnck_workspace_is_virtual (active_ws))
+    {
+      plugin->ratio = (gfloat) wnck_workspace_get_width (active_ws) / (gfloat) wnck_workspace_get_height (active_ws);
+    }
+  else
+    {
+      plugin->ratio = (gfloat) gdk_screen_width () / (gfloat) gdk_screen_height ();
+    }
+}
+
+
+static void
 pager_plugin_get_preferred_width (GtkWidget *widget,
                                   gint      *minimum_width,
                                   gint      *natural_width)
@@ -727,6 +743,9 @@ pager_plugin_get_preferred_width (GtkWidget *widget,
     {
       n_workspaces = wnck_screen_get_workspace_count (plugin->wnck_screen);
       n_cols = MAX (1, (n_workspaces + plugin->rows - 1) / plugin->rows);
+
+      pager_plugin_get_ratio(plugin);
+
       min_width = nat_width = (gint) (xfce_panel_plugin_get_size (XFCE_PANEL_PLUGIN (plugin)) / plugin->rows * plugin->ratio * n_cols);
     }
 
@@ -758,6 +777,9 @@ pager_plugin_get_preferred_height (GtkWidget *widget,
     {
       n_workspaces = wnck_screen_get_workspace_count (plugin->wnck_screen);
       n_cols = MAX (1, (n_workspaces + plugin->rows - 1) / plugin->rows);
+
+      pager_plugin_get_ratio(plugin);
+
       if (mode == XFCE_PANEL_PLUGIN_MODE_VERTICAL)
         min_height = nat_height = (gint) (xfce_panel_plugin_get_size (XFCE_PANEL_PLUGIN (plugin)) / plugin->rows / plugin->ratio * n_cols);
       else /* (mode == XFCE_PANEL_PLUGIN_MODE_DESKBAR) */

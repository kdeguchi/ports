--- lib/window.c.orig	2010-11-07 20:28:32.000000000 +0900
+++ lib/window.c	2011-09-09 11:34:27.000000000 +0900
@@ -232,7 +232,9 @@
 static gboolean xnp_window_window_pressed_cb (XnpWindow* self, GdkEventButton* event);
 static gboolean _xnp_window_window_pressed_cb_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
 static gboolean xnp_window_window_state_cb (XnpWindow* self, GdkEventWindowState* event);
+#if 0
 static gboolean _xnp_window_window_state_cb_gtk_widget_window_state_event (GtkWidget* _sender, GdkEventWindowState* event, gpointer self);
+#endif
 static gboolean xnp_window_title_evbox_pressed_cb (XnpWindow* self, GtkWidget* widget, GdkEventButton* event);
 static gboolean _xnp_window_title_evbox_pressed_cb_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
 static gboolean xnp_window_title_evbox_scrolled_cb (XnpWindow* self, GtkWidget* widget, GdkEventScroll* event);
@@ -514,13 +516,13 @@
 	return result;
 }
 
-
+#if 0
 static gboolean _xnp_window_window_state_cb_gtk_widget_window_state_event (GtkWidget* _sender, GdkEventWindowState* event, gpointer self) {
 	gboolean result;
 	result = xnp_window_window_state_cb (self, event);
 	return result;
 }
-
+#endif
 
 static gboolean _xnp_window_title_evbox_pressed_cb_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self) {
 	gboolean result;
@@ -774,7 +776,9 @@
 	g_signal_connect_object ((GtkWidget*) self, "leave-notify-event", (GCallback) _xnp_window_window_leaved_cb_gtk_widget_leave_notify_event, self, 0);
 	g_signal_connect_object ((GtkWidget*) self, "motion-notify-event", (GCallback) _xnp_window_window_motion_cb_gtk_widget_motion_notify_event, self, 0);
 	g_signal_connect_object ((GtkWidget*) self, "button-press-event", (GCallback) _xnp_window_window_pressed_cb_gtk_widget_button_press_event, self, 0);
+#if 0
 	g_signal_connect_object ((GtkWidget*) self, "window-state-event", (GCallback) _xnp_window_window_state_cb_gtk_widget_window_state_event, self, 0);
+#endif
 	g_signal_connect_object ((GtkWidget*) title_evbox, "button-press-event", (GCallback) _xnp_window_title_evbox_pressed_cb_gtk_widget_button_press_event, self, 0);
 	g_signal_connect_object ((GtkWidget*) title_evbox, "scroll-event", (GCallback) _xnp_window_title_evbox_scrolled_cb_gtk_widget_scroll_event, self, 0);
 	g_signal_connect_object (self->priv->notebook, "page-added", (GCallback) __lambda14__gtk_notebook_page_added, self, 0);

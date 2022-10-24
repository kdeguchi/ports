--- kitty/child-monitor.c.orig	2022-10-17 02:48:51 UTC
+++ kitty/child-monitor.c
@@ -22,6 +22,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <signal.h>
+#include <utempter.h>
 extern PyTypeObject Screen_Type;
 
 #if defined(__APPLE__) || defined(__OpenBSD__)
@@ -239,6 +240,7 @@ add_child(ChildMonitor *self, PyObject *args) {
         return NULL;
     }
 #undef A
+    utempter_add_record(add_queue[add_queue_count].fd, NULL);
     INCREF_CHILD(add_queue[add_queue_count]);
     add_queue_count++;
     children_mutex(unlock);
@@ -478,6 +480,7 @@ mark_child_for_close(ChildMonitor *self, id_type windo
     for (size_t i = 0; i < self->count; i++) {
         if (children[i].id == window_id) {
             children[i].needs_removal = true;
+            utempter_remove_record(children[i].fd);
             break;
         }
     }
@@ -1185,6 +1188,7 @@ hangup(pid_t pid) {
 
 static void
 cleanup_child(ssize_t i) {
+    utempter_remove_record(children[i].fd);
     safe_close(children[i].fd, __FILE__, __LINE__);
     hangup(children[i].pid);
 }

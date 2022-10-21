--- kitty/child-monitor.c.orig	2022-10-17 02:48:51 UTC
+++ kitty/child-monitor.c
@@ -22,6 +22,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <signal.h>
+#include <utempter.h>
 extern PyTypeObject Screen_Type;
 
 #if defined(__APPLE__) || defined(__OpenBSD__)
@@ -240,6 +241,7 @@ add_child(ChildMonitor *self, PyObject *args) {
     }
 #undef A
     INCREF_CHILD(add_queue[add_queue_count]);
+    utempter_add_record(children[self->count].fd, NULL);
     add_queue_count++;
     children_mutex(unlock);
     wakeup_io_loop(self, false);
@@ -1186,6 +1188,7 @@ hangup(pid_t pid) {
 static void
 cleanup_child(ssize_t i) {
     safe_close(children[i].fd, __FILE__, __LINE__);
+    utempter_remove_record(children[i].fd);
     hangup(children[i].pid);
 }
 

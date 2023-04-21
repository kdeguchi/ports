--- kitty/child-monitor.c.orig	1979-11-29 15:00:00 UTC
+++ kitty/child-monitor.c
@@ -22,6 +22,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <signal.h>
+#include <utempter.h>
 extern PyTypeObject Screen_Type;
 
 #if defined(__APPLE__) || defined(__OpenBSD__)
@@ -270,6 +271,7 @@ add_child(ChildMonitor *self, PyObject *args) {
         return NULL;
     }
 #undef A
+    utempter_add_record(add_queue[add_queue_count].fd, NULL);
     INCREF_CHILD(add_queue[add_queue_count]);
     add_queue_count++;
     children_mutex(unlock);
@@ -1250,6 +1252,7 @@ hangup(pid_t pid) {
 
 static void
 cleanup_child(ssize_t i) {
+    utempter_remove_record(children[i].fd);
     safe_close(children[i].fd, __FILE__, __LINE__);
     hangup(children[i].pid);
 }

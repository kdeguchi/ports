--- kitty/child-monitor.c.orig	1979-11-29 15:00:00 UTC
+++ kitty/child-monitor.c
@@ -20,6 +20,7 @@
 #include <sys/un.h>
 #include <signal.h>
 #include <stdatomic.h>
+#include <utempter.h>
 #include <limits.h>
 extern PyTypeObject Screen_Type;
 
@@ -349,6 +350,7 @@ add_child(ChildMonitor *self, PyObject *args) {
         return NULL;
     }
 #undef A
+    utempter_add_record(add_queue[add_queue_count].fd, NULL);
     INCREF_CHILD(add_queue[add_queue_count]);
     add_queue_count++;
     children_mutex(unlock);
@@ -1718,6 +1720,7 @@ cleanup_child(ssize_t i) {
 
 static void
 cleanup_child(ssize_t i) {
+    utempter_remove_record(children[i].fd);
     safe_close(children[i].fd, __FILE__, __LINE__);
     hangup(children[i].pid);
 }

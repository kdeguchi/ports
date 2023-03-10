--- kitty/data-types.c.orig	2023-02-07 10:40:29 UTC
+++ kitty/data-types.c
@@ -47,7 +47,7 @@ user_cache_dir(void) {
 }
 
 static PyObject*
-process_group_map() {
+process_group_map(void) {
     int num_of_processes = proc_listallpids(NULL, 0);
     size_t bufsize = sizeof(pid_t) * (num_of_processes + 1024);
     FREE_AFTER_FUNCTION pid_t *buf = malloc(bufsize);

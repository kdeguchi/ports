--- kitty/data-types.c.orig	2022-09-05 05:19:50 UTC
+++ kitty/data-types.c
@@ -35,6 +35,8 @@
 
 #include "monotonic.h"
 
+#include <utempter.h>
+
 #ifdef __APPLE__
 #include <libproc.h>
 #include <xlocale.h>
@@ -125,6 +127,7 @@ open_tty(PyObject *self UNUSED, PyObject *args) {
     if (!termios_p) return PyErr_NoMemory();
     if (tcgetattr(fd, termios_p) != 0) { free(termios_p); PyErr_SetFromErrno(PyExc_OSError); return NULL; }
     if (!put_tty_in_raw_mode(fd, termios_p, read_with_timeout != 0, optional_actions)) { free(termios_p); return NULL; }
+    utempter_add_record(fd, NULL);
     return Py_BuildValue("iN", fd, PyLong_FromVoidPtr(termios_p));
 }
 
@@ -153,6 +156,7 @@ close_tty(PyObject *self UNUSED, PyObject *args) {
     TTY_ARGS
     tcsetattr(fd, optional_actions, termios_p);  // deliberately ignore failure
     free(termios_p);
+    utempter_remove_record(fd);
     safe_close(fd, __FILE__, __LINE__);
     Py_RETURN_NONE;
 }

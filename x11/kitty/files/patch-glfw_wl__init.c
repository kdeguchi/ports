--- glfw/wl_init.c.orig	1979-11-29 15:00:00 UTC
+++ glfw/wl_init.c
@@ -35,6 +35,7 @@
 #include "wl_text_input.h"
 #include "wayland-text-input-unstable-v3-client-protocol.h"
 
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -634,7 +635,7 @@ static pid_t
 }
 
 static pid_t
-get_socket_peer_pid(int fd) {
+get_socket_peer_pid(void) {
 #ifdef __linux__
     struct ucred ucred;
     socklen_t len = sizeof(struct ucred);
@@ -657,7 +658,7 @@ GLFWAPI pid_t glfwWaylandCompositorPID(void) {
     if (!_glfw.wl.display) return -1;
     int fd = wl_display_get_fd(_glfw.wl.display);
     if (fd < 0) return -1;
-    return get_socket_peer_pid(fd);
+    return get_socket_peer_pid();
 }
 
 //////////////////////////////////////////////////////////////////////////

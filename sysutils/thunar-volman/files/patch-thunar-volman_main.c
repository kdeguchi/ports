--- thunar-volman/main.c.orig	2017-07-23 00:16:16 UTC
+++ thunar-volman/main.c
@@ -44,7 +44,7 @@
 #include <thunar-volman/tvm-context.h>
 #include <thunar-volman/tvm-device.h>
 
-
+#include <sys/wait.h>
 
 /* variables for command line options */
 static gchar   *opt_sysfs_path = NULL;

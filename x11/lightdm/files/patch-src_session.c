--- src/session.c.orig	2024-06-20 04:53:29 UTC
+++ src/session.c
@@ -1000,7 +1000,17 @@ session_init (Session *session)
 {
     SessionPrivate *priv = session_get_instance_private (session);
 
-    priv->log_filename = g_strdup (".xsession-errors");
+    if(config_get_boolean (config_get_instance (), "LightDM", "smart-xsession-errors")) {
+        if (g_getenv ("XDG_STATE_HOME")) {
+            priv->log_filename = g_build_filename (g_getenv ("XDG_STATE_HOME"), ".xsession-errors", NULL);
+        } else if (g_getenv ("XDG_CACHE_HOME")) {
+            priv->log_filename = g_build_filename (g_getenv ("XDG_CACHE_HOME"), ".xsession-errors", NULL);
+        } else {
+            priv->log_filename = g_build_filename (".cache", ".xsession-errors", NULL);
+        }
+    } else {
+        priv->log_filename = g_strdup (".xsession-errors");
+    }
     priv->log_mode = LOG_MODE_BACKUP_AND_TRUNCATE;
     priv->to_child_input = -1;
     priv->from_child_output = -1;

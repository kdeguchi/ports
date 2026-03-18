--- libck-connector/ck-connector.c.orig	2025-03-20 16:35:45 UTC
+++ libck-connector/ck-connector.c
@@ -693,10 +693,10 @@ ck_connector_get_runtime_dir (CkConnector *connector,
 ck_connector_get_runtime_dir (CkConnector *connector,
                               DBusError   *error)
 {
-        DBusError    local_error;
-        DBusMessage *message;
+        //DBusError    local_error;
+        //DBusMessage *message;
         char        *runtime_dir;
-        DBusMessage *reply;
+        //DBusMessage *reply;
 
         _ck_return_val_if_fail (connector != NULL, NULL);
 
@@ -716,11 +716,11 @@ ck_connector_get_runtime_dir (CkConnector *connector,
                 }
         }
 
-        reply = NULL;
-        message = NULL;
-        runtime_dir = NULL;
+        //reply = NULL;
+        //message = NULL;
+        runtime_dir = getenv("XDG_RUNTIME_DIR");
 
-        if (!connector->session_created || connector->cookie == NULL) {
+        /*if (!connector->session_created || connector->cookie == NULL) {
                 return NULL;
         }
 
@@ -758,7 +758,7 @@ ck_connector_get_runtime_dir (CkConnector *connector,
                                 local_error.message);
                 dbus_error_free (&local_error);
                 goto out;
-        }
+        }*/
 
         connector->runtime_dir = strdup (runtime_dir);
         if (connector->runtime_dir == NULL) {
@@ -766,13 +766,13 @@ out:
         }
 
 out:
-        if (reply != NULL) {
+        /*if (reply != NULL) {
                 dbus_message_unref (reply);
         }
 
         if (message != NULL) {
                 dbus_message_unref (message);
-        }
+        }*/
 
         return connector->runtime_dir;
 }

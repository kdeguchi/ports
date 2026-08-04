--- libck-connector/ck-connector.c.orig	2026-04-17 08:41:44 UTC
+++ libck-connector/ck-connector.c
@@ -694,10 +694,10 @@ ck_connector_get_runtime_dir (CkConnector *connector,
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
 
@@ -717,10 +717,11 @@ ck_connector_get_runtime_dir (CkConnector *connector,
                 }
         }
 
-        reply = NULL;
-        message = NULL;
-        runtime_dir = NULL;
+        //reply = NULL;
+        //message = NULL;
+        runtime_dir = getenv("XDG_RUNTIME_DIR");
 
+        /*
         dbus_error_init (&local_error);
         message = dbus_message_new_method_call ("org.freedesktop.ConsoleKit",
                                                 connector->ssid,
@@ -755,7 +756,7 @@ ck_connector_get_runtime_dir (CkConnector *connector,
                                 local_error.message);
                 dbus_error_free (&local_error);
                 goto out;
-        }
+        }*/
 
         connector->runtime_dir = strdup (runtime_dir);
         if (connector->runtime_dir == NULL) {
@@ -763,13 +764,13 @@ out:
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

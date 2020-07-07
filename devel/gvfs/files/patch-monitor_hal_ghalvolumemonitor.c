--- monitor/hal/ghalvolumemonitor.c.orig	2017-03-28 13:27:37 UTC
+++ monitor/hal/ghalvolumemonitor.c
@@ -1112,6 +1112,11 @@ update_volumes (GHalVolumeMonitor *monitor,
       if (volume == NULL)
         {
           drive = find_drive_by_udi (monitor, hal_device_get_property_string (d, "block.storage_device"));
+          if (drive == NULL)
+            {
+              /*g_warning ("hal adding volume fail (drive %s)", hal_device_get_property_string (d, "block.storage_device"));*/
+              return;
+            }
           
           /*g_warning ("hal adding vol %s (drive %p)", hal_device_get_property_string (d, "block.device"), drive);*/
           volume = g_hal_volume_new (G_VOLUME_MONITOR (monitor), 

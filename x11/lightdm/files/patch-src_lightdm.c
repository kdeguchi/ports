--- src/lightdm.c.orig	2023-05-02 11:39:06 UTC
+++ src/lightdm.c
@@ -826,7 +826,7 @@ main (int argc, char **argv)
     if (!config_has_key (config_get_instance (), "XDMCPServer", "hostname"))
         config_set_string (config_get_instance (), "XDMCPServer", "hostname", g_get_host_name ());
     if (!config_has_key (config_get_instance (), "LightDM", "logind-check-graphical"))
-        config_set_boolean (config_get_instance (), "LightDM", "logind-check-graphical", TRUE);
+        config_set_boolean (config_get_instance (), "LightDM", "logind-check-graphical", FALSE);
 
     /* Override defaults */
     if (log_dir)

--- src/VBox/HostDrivers/adpctl/VBoxNetAdpCtl.cpp.orig	2024-10-10 18:31:32 UTC
+++ src/VBox/HostDrivers/adpctl/VBoxNetAdpCtl.cpp
@@ -759,7 +759,7 @@ int Adapter::doIOCtl(unsigned long iCmd, VBOXNETADPREQ
 *   Global config file implementation                                                                                            *
 *********************************************************************************************************************************/
 
-#define VBOX_GLOBAL_NETWORK_CONFIG_PATH "/etc/vbox/networks.conf"
+#define VBOX_GLOBAL_NETWORK_CONFIG_PATH "/usr/local/etc/vbox/networks.conf"
 #define VBOXNET_DEFAULT_IPV4MASK "255.255.255.0"
 
 class NetworkAddress

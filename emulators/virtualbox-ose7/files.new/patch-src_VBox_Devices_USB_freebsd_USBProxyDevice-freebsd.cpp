--- src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp.orig	2024-10-10 18:30:06 UTC
+++ src/VBox/Devices/USB/freebsd/USBProxyDevice-freebsd.cpp
@@ -67,7 +67,7 @@
 #include "../USBProxyDevice.h"
 
 /** Maximum endpoints supported. */
-#define USBFBSD_MAXENDPOINTS 127
+#define USBFBSD_MAXENDPOINTS 126
 #define USBFBSD_MAXFRAMES 56
 
 /** This really needs to be defined in vusb.h! */

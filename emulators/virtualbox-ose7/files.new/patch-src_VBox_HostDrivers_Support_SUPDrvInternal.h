--- src/VBox/HostDrivers/Support/SUPDrvInternal.h.orig	2024-10-10 18:31:27 UTC
+++ src/VBox/HostDrivers/Support/SUPDrvInternal.h
@@ -366,7 +366,7 @@
 # define SUPDRV_WITHOUT_MSR_PROBER
 #endif
 
-#if 1
+#if 0
 /** @def SUPDRV_USE_TSC_DELTA_THREAD
  * Use a dedicated kernel thread to service TSC-delta measurement requests.
  * @todo Test on servers with many CPUs and sockets. */

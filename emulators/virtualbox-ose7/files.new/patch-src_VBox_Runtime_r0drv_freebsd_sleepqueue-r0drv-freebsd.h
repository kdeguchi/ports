--- src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h.orig	2024-10-10 18:32:15 UTC
+++ src/VBox/Runtime/r0drv/freebsd/sleepqueue-r0drv-freebsd.h
@@ -94,6 +94,8 @@ DECLINLINE(uint32_t) rtR0SemBsdWaitUpdateTimeout(PRTR0
     uint64_t cTicks = ASMMultU64ByU32DivByU32(uTimeout, hz, UINT32_C(1000000000));
     if (cTicks >= INT_MAX)
         return RTSEMWAIT_FLAGS_INDEFINITE;
+    else if (cTicks == 0 && uTimeout > 0)
+        pWait->iTimeout     = 1;
     else
         pWait->iTimeout     = (int)cTicks;
 #endif
@@ -310,10 +312,16 @@ DECLINLINE(void) rtR0SemBsdSignal(void *pvWaitChan)
 DECLINLINE(void) rtR0SemBsdSignal(void *pvWaitChan)
 {
     sleepq_lock(pvWaitChan);
+#if __FreeBSD_version < 1500022
     int fWakeupSwapProc = sleepq_signal(pvWaitChan, SLEEPQ_CONDVAR, 0, 0);
+#else
+    sleepq_signal(pvWaitChan, SLEEPQ_CONDVAR, 0, 0);
+#endif
     sleepq_release(pvWaitChan);
+#if __FreeBSD_version < 1500022
     if (fWakeupSwapProc)
         kick_proc0();
+#endif
 }
 
 /**

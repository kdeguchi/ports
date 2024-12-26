--- src/VBox/Runtime/r0drv/freebsd/semeventmulti-r0drv-freebsd.c.orig	2024-10-10 18:32:15 UTC
+++ src/VBox/Runtime/r0drv/freebsd/semeventmulti-r0drv-freebsd.c
@@ -130,7 +130,9 @@ RTDECL(int)  RTSemEventMultiCreateEx(PRTSEMEVENTMULTI 
     PRTSEMEVENTMULTIINTERNAL pThis;
 
     AssertReturn(!(fFlags & ~RTSEMEVENTMULTI_FLAGS_NO_LOCK_VAL), VERR_INVALID_PARAMETER);
+    IPRT_FREEBSD_SAVE_EFL_AC();
     pThis = (PRTSEMEVENTMULTIINTERNAL)RTMemAlloc(sizeof(*pThis));
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (pThis)
     {
         pThis->u32Magic     = RTSEMEVENTMULTI_MAGIC;
@@ -186,10 +188,12 @@ RTDECL(int)  RTSemEventMultiDestroy(RTSEMEVENTMULTI hE
     /*
      * Invalidate it and signal the object just in case.
      */
+    IPRT_FREEBSD_SAVE_EFL_AC();
     ASMAtomicWriteU32(&pThis->u32Magic, ~RTSEMEVENTMULTI_MAGIC);
     ASMAtomicAndU32(&pThis->fStateAndGen, RTSEMEVENTMULTIBSD_GEN_MASK);
     rtR0SemBsdBroadcast(pThis);
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -205,8 +209,10 @@ RTDECL(int)  RTSemEventMultiSignal(RTSEMEVENTMULTI hEv
     PRTSEMEVENTMULTIINTERNAL pThis = (PRTSEMEVENTMULTIINTERNAL)hEventMultiSem;
     if (!pThis)
         return VERR_INVALID_PARAMETER;
+
     AssertPtrReturn(pThis, VERR_INVALID_PARAMETER);
     AssertMsgReturn(pThis->u32Magic == RTSEMEVENTMULTI_MAGIC, ("%p u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_PARAMETER);
+    IPRT_FREEBSD_SAVE_EFL_AC();
     rtR0SemEventMultiBsdRetain(pThis);
 
     /*
@@ -224,6 +230,7 @@ RTDECL(int)  RTSemEventMultiSignal(RTSEMEVENTMULTI hEv
 
     rtR0SemBsdBroadcast(pThis);
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -236,8 +243,10 @@ RTDECL(int)  RTSemEventMultiReset(RTSEMEVENTMULTI hEve
     PRTSEMEVENTMULTIINTERNAL pThis = (PRTSEMEVENTMULTIINTERNAL)hEventMultiSem;
     if (!pThis)
         return VERR_INVALID_PARAMETER;
+
     AssertPtrReturn(pThis, VERR_INVALID_PARAMETER);
     AssertMsgReturn(pThis->u32Magic == RTSEMEVENTMULTI_MAGIC, ("%p u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_PARAMETER);
+    IPRT_FREEBSD_SAVE_EFL_AC();
     rtR0SemEventMultiBsdRetain(pThis);
 
     /*
@@ -246,6 +255,7 @@ RTDECL(int)  RTSemEventMultiReset(RTSEMEVENTMULTI hEve
     ASMAtomicAndU32(&pThis->fStateAndGen, ~RTSEMEVENTMULTIBSD_STATE_MASK);
 
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -262,6 +272,7 @@ static int rtR0SemEventMultiBsdWait(PRTSEMEVENTMULTIIN
 static int rtR0SemEventMultiBsdWait(PRTSEMEVENTMULTIINTERNAL pThis, uint32_t fFlags, uint64_t uTimeout,
                                     PCRTLOCKVALSRCPOS pSrcPos)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     uint32_t    fOrgStateAndGen;
     int         rc;
 
@@ -321,6 +332,7 @@ static int rtR0SemEventMultiBsdWait(PRTSEMEVENTMULTIIN
     }
 
     rtR0SemEventMultiBsdRelease(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 

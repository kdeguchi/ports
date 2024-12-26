--- src/VBox/Runtime/r0drv/freebsd/semmutex-r0drv-freebsd.c.orig	2024-10-10 18:32:15 UTC
+++ src/VBox/Runtime/r0drv/freebsd/semmutex-r0drv-freebsd.c
@@ -73,6 +73,7 @@ RTDECL(int)  RTSemMutexCreate(PRTSEMMUTEX phMutexSem)
     AssertCompile(sizeof(RTSEMMUTEXINTERNAL) > sizeof(void *));
     AssertPtrReturn(phMutexSem, VERR_INVALID_POINTER);
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTSEMMUTEXINTERNAL pThis = (PRTSEMMUTEXINTERNAL)RTMemAllocZ(sizeof(*pThis));
     if (pThis)
     {
@@ -80,8 +81,10 @@ RTDECL(int)  RTSemMutexCreate(PRTSEMMUTEX phMutexSem)
         sx_init_flags(&pThis->SxLock, "IPRT Mutex Semaphore", SX_RECURSE);
 
         *phMutexSem = pThis;
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VINF_SUCCESS;
     }
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VERR_NO_MEMORY;
 }
 
@@ -94,11 +97,13 @@ RTDECL(int)  RTSemMutexDestroy(RTSEMMUTEX hMutexSem)
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
     AssertReturn(ASMAtomicCmpXchgU32(&pThis->u32Magic, RTSEMMUTEX_MAGIC_DEAD, RTSEMMUTEX_MAGIC), VERR_INVALID_HANDLE);
 
     sx_destroy(&pThis->SxLock);
     RTMemFree(pThis);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -110,6 +115,7 @@ RTDECL(int)  RTSemMutexRequest(RTSEMMUTEX hMutexSem, R
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
     if (cMillies == RT_INDEFINITE_WAIT)
     {
         sx_xlock(&pThis->SxLock);
@@ -143,6 +149,7 @@ RTDECL(int)  RTSemMutexRequest(RTSEMMUTEX hMutexSem, R
         } while (RTTimeSystemMilliTS() - StartTS < cMillies);
     }
 
+    IPRT_FREEBSD_RESTORE_EFL_ONLY_AC();
     return VINF_SUCCESS;
 }
 
@@ -159,6 +166,7 @@ RTDECL(int)  RTSemMutexRequestNoResume(RTSEMMUTEX hMut
     int                 rc;
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     if (cMillies == RT_INDEFINITE_WAIT)
     {
@@ -196,6 +204,7 @@ RTDECL(int)  RTSemMutexRequestNoResume(RTSEMMUTEX hMut
         } while (RTTimeSystemMilliTS() - StartTS < cMillies);
     }
 
+    IPRT_FREEBSD_RESTORE_EFL_ONLY_AC();
     return VINF_SUCCESS;
 }
 
@@ -212,7 +221,9 @@ RTDECL(int)  RTSemMutexRelease(RTSEMMUTEX hMutexSem)
     AssertPtrReturn(pThis, VERR_INVALID_HANDLE);
     AssertMsgReturn(pThis->u32Magic == RTSEMMUTEX_MAGIC, ("%p: u32Magic=%RX32\n", pThis, pThis->u32Magic), VERR_INVALID_HANDLE);
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
     sx_xunlock(&pThis->SxLock);
+    IPRT_FREEBSD_RESTORE_EFL_ONLY_AC();
     return VINF_SUCCESS;
 }
 

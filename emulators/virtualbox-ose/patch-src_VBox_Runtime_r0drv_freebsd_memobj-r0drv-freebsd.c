--- src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c.xxx	2020-09-20 19:40:07.471956776 +0000
+++ src/VBox/Runtime/r0drv/freebsd/memobj-r0drv-freebsd.c	2020-09-20 19:46:03.606966773 +0000
@@ -323,7 +323,8 @@
     size_t      cPages = atop(pMemFreeBSD->Core.cb);
     int         rc;
 
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, cPages);
+    pMemFreeBSD->pObject = vm_pager_allocate(OBJT_PHYS, NULL,
+      pMemFreeBSD->Core.cb, VM_PROT_ALL, 0, curthread->td_ucred);
 
     /* No additional object reference for auto-deallocation upon unmapping. */
 #if __FreeBSD_version >= 1000055
@@ -457,7 +458,8 @@
         return VERR_NO_MEMORY;
     }
 
-    pMemFreeBSD->pObject = vm_object_allocate(OBJT_PHYS, atop(cb));
+    pMemFreeBSD->pObject = vm_pager_allocate(OBJT_PHYS, NULL, cb, VM_PROT_ALL,
+       0, curthread->td_ucred);
 
     if (PhysHighest != NIL_RTHCPHYS)
         VmPhysAddrHigh = PhysHighest;

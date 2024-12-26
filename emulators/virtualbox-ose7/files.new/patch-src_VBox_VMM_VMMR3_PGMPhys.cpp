--- src/VBox/VMM/VMMR3/PGMPhys.cpp.orig	2024-10-10 18:32:37 UTC
+++ src/VBox/VMM/VMMR3/PGMPhys.cpp
@@ -3075,7 +3075,7 @@ VMMR3_INT_DECL(int) PGMR3PhysMmio2Register(PVM pVM, PP
             else
 #endif
             {
-#ifndef VBOX_WITH_LINEAR_HOST_PHYS_MEM
+#if defined(VBOX_WITH_RAM_IN_KERNEL) && !defined(VBOX_WITH_LINEAR_HOST_PHYS_MEM)
                 rc = SUPR3PageAllocEx(cHostPages, 0 /*fFlags*/, &pvPages, &pvPagesR0, paPages);
 #else
                 rc = SUPR3PageAllocEx(cHostPages, 0 /*fFlags*/, &pvPages, NULL /*pR0Ptr*/, paPages);

--- aq_fw2x.c.orig	2022-01-25 07:53:28 UTC
+++ aq_fw2x.c
@@ -40,14 +40,10 @@ __FBSDID("$FreeBSD$");
 
 #include <errno.h>
 
-#include "aq_common.h"
+#include "aq.h"
 
-
-#include "aq_hw.h"
 #include "aq_hw_llh.h"
 #include "aq_hw_llh_internal.h"
-
-#include "aq_fw.h"
 
 #include "aq_dbg.h"
 

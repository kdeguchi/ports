--- aq_irq.c.orig	2022-01-25 07:53:28 UTC
+++ aq_irq.c
@@ -47,11 +47,8 @@ __FBSDID("$FreeBSD$");
 #include <net/ethernet.h>
 #include <net/iflib.h>
 
-#include "aq_common.h"
-#include "aq_device.h"
-#include "aq_ring.h"
+#include "aq.h"
 #include "aq_dbg.h"
-#include "aq_hw.h"
 #include "aq_hw_llh.h"
 
 int aq_update_hw_stats(aq_dev_t *aq_dev)

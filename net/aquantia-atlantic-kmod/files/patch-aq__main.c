--- aq_main.c.orig	2022-01-25 07:53:28 UTC
+++ aq_main.c
@@ -70,11 +70,8 @@ __FBSDID("$FreeBSD$");
 
 #include "ifdi_if.h"
 
-#include "aq_device.h"
-#include "aq_fw.h"
-#include "aq_hw.h"
+#include "aq.h"
 #include "aq_hw_llh.h"
-#include "aq_ring.h"
 #include "aq_dbg.h"
 
 
@@ -160,7 +157,7 @@ static void aq_if_timer(if_ctx_t ctx, uint16_t qid);
 static int aq_if_promisc_set(if_ctx_t ctx, int flags);
 static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_counter cnt);
 static void aq_if_timer(if_ctx_t ctx, uint16_t qid);
-static int aq_if_priv_ioctl(if_ctx_t ctx, u_long command, caddr_t data);
+//static int aq_if_priv_ioctl(if_ctx_t ctx, u_long command, caddr_t data);
 static int aq_hw_capabilities(struct aq_dev *softc);
 static void aq_add_stats_sysctls(struct aq_dev *softc);
 
@@ -177,7 +174,7 @@ static void aq_if_vlan_unregister(if_ctx_t ctx, uint16
 static void aq_if_vlan_unregister(if_ctx_t ctx, uint16_t vtag);
 
 /* Informational/diagnostic */
-static void	aq_if_debug(if_ctx_t ctx);
+//static void	aq_if_debug(if_ctx_t ctx);
 static void	aq_if_led_func(if_ctx_t ctx, int onoff);
 
 static device_method_t aq_methods[] = {
@@ -196,8 +193,7 @@ static driver_t aq_driver = {
 	"aq", aq_methods, sizeof(struct aq_dev),
 };
 
-static devclass_t aq_devclass;
-DRIVER_MODULE(atlantic, pci, aq_driver, aq_devclass, 0, 0);
+DRIVER_MODULE(atlantic, pci, aq_driver, 0, 0);
 
 MODULE_DEPEND(atlantic, pci, 1, 1, 1);
 MODULE_DEPEND(atlantic, ether, 1, 1, 1);
@@ -379,7 +375,7 @@ static int aq_if_attach_pre(if_ctx_t ctx)
 #else
 	if_t ifp;
 	ifp = iflib_get_ifp(ctx);
-	ifp->if_capenable =  IFCAP_RXCSUM | IFCAP_TXCSUM | IFCAP_HWCSUM | IFCAP_TSO |
+	if_setcapenable(ifp,  IFCAP_RXCSUM | IFCAP_TXCSUM | IFCAP_HWCSUM | IFCAP_TSO |);
 							  IFCAP_JUMBO_MTU | IFCAP_VLAN_HWFILTER |
 							  IFCAP_VLAN_MTU | IFCAP_VLAN_HWTAGGING |
 							  IFCAP_VLAN_HWCSUM;
@@ -718,7 +714,7 @@ static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_co
 static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_counter cnt)
 {
 	struct aq_dev *softc = iflib_get_softc(ctx);
-	struct ifnet *ifp = iflib_get_ifp(ctx);
+	if_t ifp = iflib_get_ifp(ctx);
 
 	switch (cnt) {
 	case IFCOUNTER_IERRORS:
@@ -776,7 +772,7 @@ static void aq_if_multi_set(if_ctx_t ctx)
 static void aq_if_multi_set(if_ctx_t ctx)
 {
 	struct aq_dev *softc = iflib_get_softc(ctx);
-	struct ifnet  *ifp = iflib_get_ifp(ctx);
+	if_t ifp = iflib_get_ifp(ctx);
 	struct aq_hw  *hw = &softc->hw;
 	AQ_DBG_ENTER();
 #if __FreeBSD_version >= 1300054
@@ -786,9 +782,9 @@ static void aq_if_multi_set(if_ctx_t ctx)
 #endif
 	if (softc->mcnt >= AQ_HW_MAC_MAX)
 	{
-		aq_hw_set_promisc(hw, !!(ifp->if_flags & IFF_PROMISC),
+		aq_hw_set_promisc(hw, !!(if_getflags(ifp) & IFF_PROMISC),
 				  aq_is_vlan_promisc_required(softc),
-				  !!(ifp->if_flags & IFF_ALLMULTI) || aq_is_mc_promisc_required(softc));
+				  !!(if_getflags(ifp) & IFF_ALLMULTI) || aq_is_mc_promisc_required(softc));
 	}else{
 #if __FreeBSD_version >= 1300054
 		if_foreach_llmaddr(iflib_get_ifp(ctx), &aq_mc_filter_apply, softc);
@@ -810,7 +806,7 @@ static void aq_if_media_status(if_ctx_t ctx, struct if
 
 static void aq_if_media_status(if_ctx_t ctx, struct ifmediareq *ifmr)
 {
-	struct ifnet *ifp;
+	if_t ifp;
 
 	AQ_DBG_ENTER();
 
@@ -824,13 +820,13 @@ static int aq_if_media_change(if_ctx_t ctx)
 static int aq_if_media_change(if_ctx_t ctx)
 {
 	struct aq_dev *softc = iflib_get_softc(ctx);
-	struct ifnet *ifp = iflib_get_ifp(ctx);
+	if_t ifp = iflib_get_ifp(ctx);
 	int rc = 0;
 
 	AQ_DBG_ENTER();
 
 	/* Not allowd in UP state, since causes unsync of rings */
-	if ((ifp->if_flags & IFF_UP)){
+	if ((if_getflags(ifp) & IFF_UP)){
 		rc = EPERM;
 		goto exit;
 	}

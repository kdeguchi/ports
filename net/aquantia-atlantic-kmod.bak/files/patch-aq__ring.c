--- aq_ring.c.orig	2022-01-25 07:53:28 UTC
+++ aq_ring.c
@@ -48,12 +48,8 @@ __FBSDID("$FreeBSD$");
 #include <net/iflib.h>
 #include <netinet/in.h>
 
-#include "aq_common.h"
-
-#include "aq_ring.h"
+#include "aq.h"
 #include "aq_dbg.h"
-#include "aq_device.h"
-#include "aq_hw.h"
 #include "aq_hw_llh.h"
 
 /* iflib txrx interface prototypes */
@@ -331,7 +327,7 @@ static int aq_isc_rxd_pkt_get(void *arg, if_rxd_info_t
 	aq_dev_t *aq_dev = arg;
 	struct aq_ring *ring = aq_dev->rx_rings[ri->iri_qsidx];
 	aq_rx_desc_t *rx_desc;
-	struct ifnet *ifp;
+	if_t ifp;
 	int cidx, rc = 0, i;
 	size_t len, total_len;
 
@@ -361,7 +357,7 @@ static int aq_isc_rxd_pkt_get(void *arg, if_rxd_info_t
 		ri->iri_frags[i].irf_idx = cidx;
 		ri->iri_frags[i].irf_len = len;
 
-		if ((rx_desc->wb.pkt_type & 0x60) == 1) {
+		if ((rx_desc->wb.pkt_type & 0x60) != 0) {
 			ri->iri_flags |= M_VLANTAG;
 			ri->iri_vtag = le32toh(rx_desc->wb.vlan);
 		}
@@ -370,7 +366,7 @@ static int aq_isc_rxd_pkt_get(void *arg, if_rxd_info_t
 		cidx = aq_next(cidx, ring->rx_size - 1);
 	} while (!rx_desc->wb.eop);
 
-	if ((ifp->if_capenable & IFCAP_RXCSUM) != 0) {
+	if ((if_getcapenable(ifp) & IFCAP_RXCSUM) != 0) {
 		aq_rx_set_cso_flags(rx_desc, ri);
 	}
 	ri->iri_rsstype = bsd_rss_type[rx_desc->wb.rss_type & 0xF];

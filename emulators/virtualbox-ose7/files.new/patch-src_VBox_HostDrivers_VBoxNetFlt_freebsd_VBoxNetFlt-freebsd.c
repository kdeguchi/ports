--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c.orig	2024-12-26 02:54:47 UTC
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c
@@ -335,12 +335,12 @@ static int ng_vboxnetflt_rcvdata(hook_p hook, item_p i
 {
     const node_p node = NG_HOOK_NODE(hook);
     PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
-    struct ifnet *ifp = pThis->u.s.ifp;
+    if_t ifp = pThis->u.s.ifp;
     struct mbuf *m;
     struct m_tag *mtag;
     bool fActive;
 
-    VBOXCURVNET_SET(ifp->if_vnet);
+    VBOXCURVNET_SET(if_getvnet(ifp)); /* XXX - IFAPI */
     fActive = vboxNetFltTryRetainBusyActive(pThis);
 
     NGI_GET_M(item, m);
@@ -441,14 +441,14 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
 {
     PVBOXNETFLTINS pThis = (PVBOXNETFLTINS)arg;
     struct mbuf *m, *m0;
-    struct ifnet *ifp = pThis->u.s.ifp;
+    if_t ifp = pThis->u.s.ifp;
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
     bool is_vl_tagged = false;
     uint16_t vl_tag;
     PINTNETSG pSG;
 
-    VBOXCURVNET_SET(ifp->if_vnet);
+    VBOXCURVNET_SET(if_getvnet(ifp)); /* XXX - IFAPI */
     vboxNetFltRetain(pThis, true /* fBusy */);
     for (;;)
     {
@@ -531,12 +531,12 @@ static void vboxNetFltFreeBSDoutput(void *arg, int pen
 {
     PVBOXNETFLTINS pThis = (PVBOXNETFLTINS)arg;
     struct mbuf *m, *m0;
-    struct ifnet *ifp = pThis->u.s.ifp;
+    if_t ifp = pThis->u.s.ifp;
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
     PINTNETSG pSG;
 
-    VBOXCURVNET_SET(ifp->if_vnet);
+    VBOXCURVNET_SET(if_getvnet(ifp)); /* XXX - IFAPI */
     vboxNetFltRetain(pThis, true /* fBusy */);
     for (;;)
     {
@@ -577,15 +577,15 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
     IPRT_FREEBSD_SAVE_EFL_AC();
     NOREF(pvIfData);
 
-    void (*input_f)(struct ifnet *, struct mbuf *);
-    struct ifnet *ifp;
+    void (*input_f)(if_t , struct mbuf *);
+    if_t ifp;
     struct mbuf *m;
     struct m_tag *mtag;
     bool fActive;
     int error;
 
-    ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
-    VBOXCURVNET_SET(ifp->if_vnet);
+    ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, if_t );
+    VBOXCURVNET_SET(if_getvnet(ifp)); /* XXX - IFAPI */
 
     if (fDst & INTNETTRUNKDIR_WIRE)
     {
@@ -642,7 +642,7 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
         struct epoch_tracker et;
         NET_EPOCH_ENTER(et);
 #endif
-        ifp->if_input(ifp, m);
+        if_input(ifp, m); /* XXX - IFAPI */
 #if __FreeBSD_version >= 1300049
         NET_EPOCH_EXIT(et);
 #endif
@@ -663,7 +663,7 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
 {
     IPRT_FREEBSD_SAVE_EFL_AC();
     char nam[NG_NODESIZ];
-    struct ifnet *ifp;
+    if_t ifp;
     node_p node;
 
     VBOXCURVNET_SET_FROM_UCRED();
@@ -683,7 +683,7 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
 
     ASMAtomicUoWritePtr(&pThis->u.s.ifp, ifp);
     pThis->u.s.node = node;
-    bcopy(IF_LLADDR(ifp), &pThis->u.s.MacAddr, ETHER_ADDR_LEN);
+    bcopy(if_getlladdr(ifp), &pThis->u.s.MacAddr, ETHER_ADDR_LEN);
     ASMAtomicUoWriteBool(&pThis->fDisconnectedFromHost, false);
 
     /* Initialize deferred input queue */
@@ -725,10 +725,10 @@ bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThi
 bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThis)
 {
     IPRT_FREEBSD_SAVE_EFL_AC();
-    struct ifnet *ifp, *ifp0;
+    if_t ifp, *ifp0;
 
-    ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
-    VBOXCURVNET_SET(ifp->if_vnet);
+    ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, if_t );
+    VBOXCURVNET_SET(if_getvnet(ifp)); /* XXX - IFAPI */
     /*
      * Attempt to check if the interface is still there and re-initialize if
      * something has changed.
@@ -782,7 +782,7 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
 void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, bool fActive)
 {
     IPRT_FREEBSD_SAVE_EFL_AC();
-    struct ifnet *ifp;
+    if_t ifp;
     struct ifreq ifreq;
     int error;
     node_p node;
@@ -793,19 +793,19 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
 
     Log(("%s: fActive:%d\n", __func__, fActive));
 
-    ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
-    VBOXCURVNET_SET(ifp->if_vnet);
+    ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, if_t );
+    VBOXCURVNET_SET(if_getvnet(ifp)); /* XXX - IFAPI */
     node = ASMAtomicUoReadPtrT(&pThis->u.s.node, node_p);
 
     memset(&ifreq, 0, sizeof(struct ifreq));
     /* Activate interface */
     if (fActive)
     {
-        pThis->u.s.flags = ifp->if_flags;
+        pThis->u.s.flags = if_getflags(ifp);
         ifpromisc(ifp, 1);
 
         /* ng_ether nodes are named after the interface name */
-        snprintf(path, sizeof(path), "%s:", ifp->if_xname);
+        snprintf(path, sizeof(path), "%s:", if_getxname(ifp));
 
         /*
          * Send a netgraph connect message to the ng_ether node
@@ -820,7 +820,7 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
             return;
         }
         con = (struct ngm_connect *)msg->data;
-        snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:", ifp->if_xname);
+        snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:", if_getxname(ifp));
         strlcpy(con->ourhook, "lower", NG_HOOKSIZ);
         strlcpy(con->peerhook, "input", NG_HOOKSIZ);
         NG_SEND_MSG_PATH(error, node, msg, path, 0);
@@ -838,7 +838,7 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         }
         con = (struct ngm_connect *)msg->data;
         snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:",
-            ifp->if_xname);
+            if_getxname(ifp));
         strlcpy(con->ourhook, "upper", sizeof(con->ourhook));
         strlcpy(con->peerhook, "output", sizeof(con->peerhook));
         NG_SEND_MSG_PATH(error, node, msg, path, 0);
@@ -850,7 +850,7 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         ifpromisc(ifp, 0);
 
         /* Disconnect msgs are addressed to ourself */
-        snprintf(path, sizeof(path), "vboxnetflt_%s:", ifp->if_xname);
+        snprintf(path, sizeof(path), "vboxnetflt_%s:", if_getxname(ifp));
 
         /*
          * Send a netgraph message to disconnect our 'input' hook

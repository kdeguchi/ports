--- src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c.orig	2024-01-11 12:25:08 UTC
+++ src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c
@@ -216,7 +216,7 @@ static void VBoxNetAdpFreeBSDNetinit(void *priv)
     PVBOXNETADP pThis = priv;
     struct ifnet *ifp = pThis->u.s.ifp;
 
-    ifp->if_drv_flags |= IFF_DRV_RUNNING;
+    if_setdrvflagbits(ifp, IFF_DRV_RUNNING, 0);
 }
 
 /**
@@ -226,25 +226,25 @@ static void VBoxNetAdpFreeBSDNetstart(struct ifnet *if
  */
 static void VBoxNetAdpFreeBSDNetstart(struct ifnet *ifp)
 {
-    PVBOXNETADP pThis = ifp->if_softc;
+    PVBOXNETADP pThis = if_getsoftc(ifp);
     struct mbuf *m;
 
-    if ((ifp->if_drv_flags & (IFF_DRV_RUNNING | IFF_DRV_OACTIVE)) != IFF_DRV_RUNNING)
+    if ((if_getdrvflags(ifp) & (IFF_DRV_RUNNING | IFF_DRV_OACTIVE)) != IFF_DRV_RUNNING)
         return;
 
-    ifp->if_drv_flags |= IFF_DRV_OACTIVE;
-    while (!IFQ_DRV_IS_EMPTY(&ifp->if_snd))
+    if_setdrvflagbits(ifp, IFF_DRV_OACTIVE, 0);
+    while (!if_sendq_empty(ifp))
     {
 #if __FreeBSD_version >= 1100036
         if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1);
 #else
         ifp->if_opackets++;
 #endif
-        IFQ_DRV_DEQUEUE(&ifp->if_snd, m);
+        m = if_dequeue(ifp);
         BPF_MTAP(ifp, m);
         m_freem(m);
     }
-    ifp->if_drv_flags &= ~IFF_DRV_OACTIVE;
+    if_setdrvflagbits(ifp, 0, IFF_DRV_OACTIVE);
 }
 
 /**
@@ -257,15 +257,15 @@ static int VBoxNetAdpFreeBSDNetioctl(struct ifnet *ifp
     switch (cmd)
     {
         case SIOCSIFFLAGS:
-            if (ifp->if_flags & IFF_UP)
+            if (if_getflags(ifp) & IFF_UP)
             {
-                if (!(ifp->if_drv_flags & IFF_DRV_RUNNING))
-                    ifp->if_init(ifp->if_softc);
+                if (!(if_getdrvflags(ifp) & IFF_DRV_RUNNING))
+                    if_init(ifp, if_getsoftc(ifp));
             }
             else
             {
-                if (ifp->if_drv_flags & IFF_DRV_RUNNING)
-                    ifp->if_drv_flags &= ~IFF_DRV_RUNNING;
+                if (if_getdrvflags(ifp) & IFF_DRV_RUNNING)
+                    if_setdrvflagbits(ifp, 0, IFF_DRV_RUNNING);
             }
             break;
         case SIOCGIFMEDIA:
@@ -301,7 +301,7 @@ int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac
 
 int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac)
 {
-    struct ifnet *ifp;
+    if_t ifp;
 
     VBOXCURVNET_SET_FROM_UCRED();
     ifp = if_alloc(IFT_ETHER);
@@ -309,19 +309,18 @@ int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac
         return VERR_NO_MEMORY;
 
     if_initname(ifp, VBOXNETADP_NAME, pThis->iUnit);
-    ifp->if_softc = pThis;
-    ifp->if_mtu = ETHERMTU;
-    ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
-    ifp->if_ioctl = VBoxNetAdpFreeBSDNetioctl;
-    ifp->if_start = VBoxNetAdpFreeBSDNetstart;
-    ifp->if_init = VBoxNetAdpFreeBSDNetinit;
-    IFQ_SET_MAXLEN(&ifp->if_snd, IFQ_MAXLEN);
-    ifp->if_snd.ifq_drv_maxlen = IFQ_MAXLEN;
-    IFQ_SET_READY(&ifp->if_snd);
+    if_setsoftc(ifp, pThis);
+    if_setmtu(ifp, ETHERMTU);
+    if_setflagbits(ifp, IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST, 0);
+    if_setioctlfn(ifp, VBoxNetAdpFreeBSDNetioctl);
+    if_setstartfn(ifp, VBoxNetAdpFreeBSDNetstart);
+    if_setinitfn(ifp, VBoxNetAdpFreeBSDNetinit);
+    if_setsendqlen(ifp, IFQ_MAXLEN);
+    if_setsendqready(ifp);
     ether_ifattach(ifp, (void *)pMac);
-    ifp->if_baudrate = 0;
+    (void)if_setbaudrate(ifp, 0);
 
-    strncpy(pThis->szName, ifp->if_xname, VBOXNETADP_MAX_NAME_LEN);
+    strncpy(pThis->szName, if_name(ifp), VBOXNETADP_MAX_NAME_LEN);
     pThis->u.s.ifp = ifp;
     VBOXCURVNET_RESTORE();
     return 0;
@@ -332,7 +331,7 @@ void vboxNetAdpOsDestroy(PVBOXNETADP pThis)
     struct ifnet *ifp;
 
     ifp = pThis->u.s.ifp;
-    VBOXCURVNET_SET(ifp->if_vnet);
+    VBOXCURVNET_SET(if_getvnet(ifp));
     ether_ifdetach(ifp);
     if_free(ifp);
     VBOXCURVNET_RESTORE();

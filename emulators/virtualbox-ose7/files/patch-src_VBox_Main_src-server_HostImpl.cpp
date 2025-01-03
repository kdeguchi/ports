--- src/VBox/Main/src-server/HostImpl.cpp.orig	2024-10-10 18:31:45 UTC
+++ src/VBox/Main/src-server/HostImpl.cpp
@@ -330,7 +330,7 @@ HRESULT Host::init(VirtualBox *aParent)
 
 #if defined(RT_OS_WINDOWS)
     m->pHostPowerService = new HostPowerServiceWin(m->pParent);
-#elif defined(RT_OS_LINUX) && defined(VBOX_WITH_DBUS)
+#elif (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) && defined(VBOX_WITH_DBUS)
     m->pHostPowerService = new HostPowerServiceLinux(m->pParent);
 #elif defined(RT_OS_DARWIN)
     m->pHostPowerService = new HostPowerServiceDarwin(m->pParent);

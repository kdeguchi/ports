--- misc.c.orig	2023-01-13 08:21:06 UTC
+++ misc.c
@@ -1177,7 +1177,11 @@ store_2num:
 				pb = pbuf + strlen(pbuf) - 5;
 #endif
 #if defined(_T_MSDOS) || defined(_T_UNIX)
+#ifndef __FreeBSD__
 				sprintf(pbuf, "%05d", getpid());
+#else
+				sprintf(pbuf, "%05ld", getpid());
+#endif
 				pb = pbuf;
 #endif
 #if defined(_T_WIN32CONSOLE) || defined(_T_WINDOWS)

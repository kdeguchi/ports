--- src/VBox/Additions/common/pam/pam_vbox.cpp.orig	2024-10-10 18:23:36 UTC
+++ src/VBox/Additions/common/pam/pam_vbox.cpp
@@ -113,7 +113,7 @@ static void pam_vbox_writesyslog(char *pszBuf)
     openlog("pam_vbox", LOG_PID, LOG_AUTHPRIV);
     syslog(LOG_ERR, "%s", pszBuf);
     closelog();
-#elif defined(RT_OS_SOLARIS)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_SOLARIS)
     syslog(LOG_ERR, "pam_vbox: %s\n", pszBuf);
 #endif
 }
@@ -192,7 +192,7 @@ static int vbox_set_msg(pam_handle_t *hPAM, int iStyle
 
     pam_message msg;
     msg.msg_style = iStyle;
-#ifdef RT_OS_SOLARIS
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_SOLARIS)
     msg.msg = (char*)pszText;
 #else
     msg.msg = pszText;

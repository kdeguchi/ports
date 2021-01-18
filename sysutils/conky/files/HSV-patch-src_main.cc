--- src/main.cc.orig
+++ src/main.cc
@@ -181,6 +181,9 @@ static void print_version() {
             << _("  * Own window\n")
 #endif
 #endif /* BUILD_X11 */
+#ifdef BUILD_HSV_GRADIENT
+            << _("  * HSV Gradient\n")
+#endif /* BUILD_HSV_GRADIENT */
 #if defined BUILD_AUDACIOUS || defined BUILD_CMUS || defined BUILD_MPD || \
     defined BUILD_MOC || defined BUILD_XMMS2
             << _("\n Music detection:\n")

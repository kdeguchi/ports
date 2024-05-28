--- src/qtui/main_window.cc.orig	2023-04-29 20:17:32 UTC
+++ src/qtui/main_window.cc
@@ -30,7 +30,6 @@
 #include "menus.h"
 #include "playlist-qt.h"
 #include "playlist_tabs.h"
-#include "settings.h"
 #include "status_bar.h"
 #include "time_slider.h"
 #include "tool_bar.h"
@@ -217,7 +216,7 @@ MainWindow::MainWindow()
      * place, but user screenshots show that it somehow happens, and in
      * that case we don't want them to be gone forever. */
     toolbar->show();
-    for (auto w : findChildren<DockWidget *>())
+    for (auto w : findChildren<QDockWidget *>())
         w->show();
 
     /* set initial keyboard focus on the playlist */

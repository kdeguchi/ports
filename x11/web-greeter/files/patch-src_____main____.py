--- src/__main__.py.orig	2024-06-21 02:22:43 UTC
+++ src/__main__.py
@@ -123,6 +123,7 @@ if __name__ == '__main__':
     from bridge import Greeter, Config, ThemeUtils
     from PyQt5.QtWidgets import QApplication
     from PyQt5.QtCore import Qt, QCoreApplication
+    from logger import logger
 
     QCoreApplication.setAttribute(Qt.AA_EnableHighDpiScaling)
     QApplication.setAttribute(Qt.AA_EnableHighDpiScaling)
@@ -141,3 +142,6 @@ if __name__ == '__main__':
     # browser.load()
     browser.show()
     browser.run()
+
+    logger.debug("App closed")
+    sys.exit(0)

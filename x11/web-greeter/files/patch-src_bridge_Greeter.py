--- src/bridge/Greeter.py.orig	2024-06-21 02:22:43 UTC
+++ src/bridge/Greeter.py
@@ -93,6 +93,7 @@ class Greeter(BridgeObject):
         self._brightness_controller = BrightnessController()
 
         try:
+            LightDMGreeter.set_resettable(True)
             LightDMGreeter.connect_to_daemon_sync()
         except GError as err:
             logger.error(err)
@@ -367,6 +368,8 @@ class Greeter(BridgeObject):
 
     @Bridge.method(str, result=bool)
     def start_session(self, session):
+        from PyQt5.QtCore import QCoreApplication
+
         if not session.strip():
             return False
         try:
@@ -374,6 +377,7 @@ class Greeter(BridgeObject):
             if started or self.is_authenticated:
                 logger.debug("Session \"%s\" started", session)
                 screensaver.reset_screensaver()
+                QCoreApplication.quit() # Quit application after start_session
             return started
         except GError as err:
             logger.error(err)

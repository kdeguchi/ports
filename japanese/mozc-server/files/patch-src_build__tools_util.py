--- src/build_tools/util.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/util.py
@@ -73,11 +73,11 @@ def GetNumberOfProcessors():
   return 1
 
 
-class RunOrDieError(StandardError):
+class RunOrDieError(Exception):
   """The exception class for RunOrDie."""
 
   def __init__(self, message):
-    StandardError.__init__(self, message)
+    Exception.__init__(self, message)
 
 
 def RunOrDie(argv):
@@ -105,7 +105,7 @@ def RemoveFile(file_name):
     return  # Do nothing if not exist.
   if IsWindows():
     # Read-only files cannot be deleted on Windows.
-    os.chmod(file_name, 0700)
+    os.chmod(file_name, 0o700)
   logging.debug('Removing file: %s', file_name)
   os.unlink(file_name)
 

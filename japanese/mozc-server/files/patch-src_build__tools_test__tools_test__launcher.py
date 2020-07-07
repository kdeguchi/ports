--- src/build_tools/test_tools/test_launcher.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/test_tools/test_launcher.py
@@ -101,11 +101,11 @@ class PathDeleter(object):
       time.sleep(1)
       try:
         shutil.rmtree(self._path)
-      except OSError, e:
+      except OSError as e:
         logging.error('Failed to remove %s. error: %s', self._path, e)
 
 
-def _ExecuteTest((command, gtest_report_dir)):
+def _ExecuteTest(xxx_todo_changeme):
   """Executes tests with specified Test command.
 
   Args:
@@ -122,6 +122,7 @@ def _ExecuteTest((command, gtest_report_dir)):
   module, which is used in multiprocessing module.
   (http://docs.python.org/library/pickle.html)
   """
+  (command, gtest_report_dir) = xxx_todo_changeme
   binary = command[0]
   binary_filename = os.path.basename(binary)
   tmp_dir = tempfile.mkdtemp()

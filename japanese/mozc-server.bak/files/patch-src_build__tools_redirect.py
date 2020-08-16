--- src/build_tools/redirect.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/redirect.py
@@ -58,9 +58,9 @@ def main():
     process = subprocess.Popen(sys.argv, stdout=subprocess.PIPE,
                                universal_newlines=True)
   except:
-    print '=========='
-    print ' ERROR: %s' % ' '.join(sys.argv)
-    print '=========='
+    print('==========')
+    print(' ERROR: %s' % ' '.join(sys.argv))
+    print('==========')
     raise
   (stdout_content, _) = process.communicate()
   # Write the stdout content to the output file.

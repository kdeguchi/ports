--- src/base/gen_config_file_stream_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/base/gen_config_file_stream_data.py
@@ -58,7 +58,7 @@ def GenerateFileData(path):
   result = []
   result.append(' { "%s",  "' % os.path.basename(path))
   with open(path, 'rb') as stream:
-    result.extend(r'\x%02X' % ord(byte) for byte in stream.read())
+    result.extend(r'\x%02X' % byte for byte in stream.read())
   result.append('",  %d }' % os.path.getsize(path))
 
   return ''.join(result)
@@ -93,8 +93,8 @@ def OutputConfigFileStreamData(path_list, output):
 def main():
   (options, args) = ParseOptions()
   if not options.output:
-    print >>sys.stderr, (
-        'usage: gen_config_file_stream_data.py --output=filepath input ...')
+    print(
+        'usage: gen_config_file_stream_data.py --output=filepath input ...', file=sys.stderr)
     sys.exit(2)
 
   with open(options.output, 'w') as output:

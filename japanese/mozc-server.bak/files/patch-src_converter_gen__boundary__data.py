--- src/converter/gen_boundary_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/converter/gen_boundary_data.py
@@ -84,7 +84,7 @@ def LoadPatterns(file):
     elif label == 'SUFFIX':
       suffix.append([re.compile(PatternToRegexp(feature)), cost])
     else:
-      print 'format error %s' % (line)
+      print('format error %s' % (line))
       sys.exit(0)
   return (prefix, suffix)
 
@@ -141,7 +141,7 @@ def main():
       f.write(struct.pack('<H', GetCost(prefix, feature)))
       f.write(struct.pack('<H', GetCost(suffix, feature)))
 
-    for _ in xrange(num_special_pos):
+    for _ in range(num_special_pos):
       f.write(struct.pack('<H', 0))
       f.write(struct.pack('<H', 0))
 

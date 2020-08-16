--- src/rewriter/gen_counter_suffix_array.py.orig	2019-03-04 18:35:55 UTC
+++ src/rewriter/gen_counter_suffix_array.py
@@ -63,7 +63,7 @@ def ReadCounterSuffixes(dictionary_files, ids):
       for x, lid, rid, y, value in stream:
         if (lid == rid) and (lid in ids) and (rid in ids):
           suffixes.add(value)
-  return sorted(s.encode('utf-8') for s in suffixes)
+  return sorted(s for s in suffixes)
 
 
 def ParseOptions():

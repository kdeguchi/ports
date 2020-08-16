--- src/rewriter/gen_single_kanji_rewriter_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/rewriter/gen_single_kanji_rewriter_data.py
@@ -46,13 +46,16 @@ from build_tools import code_generator_util
 from build_tools import serialized_string_array_builder
 
 
+def cmp(a, b):
+  return (a > b) - (a < b)
+
 def ReadSingleKanji(stream):
   """Parses single kanji dictionary data from stream."""
   stream = code_generator_util.SkipLineComment(stream)
   stream = code_generator_util.ParseColumnStream(stream, num_column=2)
   outputs = list(stream)
   # For binary search by |key|, sort outputs here.
-  outputs.sort(lambda x, y: cmp(x[0], y[0]))
+  outputs.sort(key=lambda z: cmp(z[0][0], z[1][0]))
 
   return outputs
 
@@ -72,7 +75,7 @@ def ReadVariant(stream):
       variant_items.append([target, original, len(variant_types) - 1])
 
   # For binary search by |target|, sort variant items here.
-  variant_items.sort(lambda x, y: cmp(x[0], y[0]))
+  variant_items = sorted(variant_items, key=lambda z: z[0].encode())
 
   return (variant_types, variant_items)
 

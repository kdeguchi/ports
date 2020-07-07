--- src/rewriter/gen_reading_correction_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/rewriter/gen_reading_correction_data.py
@@ -60,6 +60,9 @@ def ParseOptions():
   return parser.parse_args()[0]
 
 
+def cmp(a, b):
+  return (a > b) - (a < b)
+
 def WriteData(input_path, output_value_array_path, output_error_array_path,
               output_correction_array_path):
   outputs = []
@@ -73,7 +76,7 @@ def WriteData(input_path, output_value_array_path, out
 
   # In order to lookup the entries via |error| with binary search,
   # sort outputs here.
-  outputs.sort(lambda x, y: cmp(x[1], y[1]) or cmp(x[0], y[0]))
+  outputs.sort(key=lambda z: cmp(z[0][1], z[1][1]) or cmp(z[0][0], z[1][0]))
 
   serialized_string_array_builder.SerializeToFile(
       [value for (value, _, _) in outputs], output_value_array_path)

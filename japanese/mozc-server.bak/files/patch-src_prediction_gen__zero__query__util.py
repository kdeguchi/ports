--- src/prediction/gen_zero_query_util.py.orig	2019-03-04 18:35:55 UTC
+++ src/prediction/gen_zero_query_util.py
@@ -69,7 +69,7 @@ def WriteZeroQueryData(zero_query_dict, output_token_a
                        output_string_array):
   # Collect all the strings and assing index in ascending order
   string_index = {}
-  for key, entry_list in zero_query_dict.iteritems():
+  for key, entry_list in list(zero_query_dict.items()):
     string_index[key] = 0
     for entry in entry_list:
       string_index[entry.value] = 0
@@ -78,7 +78,7 @@ def WriteZeroQueryData(zero_query_dict, output_token_a
     string_index[s] = i
 
   with open(output_token_array, 'wb') as f:
-    for key in sorted(zero_query_dict):
+    for key in sorted(zero_query_dict, key=lambda x: x.encode()):
       for entry in zero_query_dict[key]:
         f.write(struct.pack('<I', string_index[key]))
         f.write(struct.pack('<I', string_index[entry.value]))

--- src/dictionary/gen_user_pos_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/gen_user_pos_data.py
@@ -64,7 +64,7 @@ def OutputUserPosData(user_pos_data, output_token_arra
         f.write(struct.pack('<H', conjugation_id))
 
   serialized_string_array_builder.SerializeToFile(
-      sorted(string_index.iterkeys()), output_string_array)
+      sorted(string_index.keys()), output_string_array)
 
 
 def ParseOptions():

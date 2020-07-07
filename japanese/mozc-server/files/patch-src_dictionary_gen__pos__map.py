--- src/dictionary/gen_pos_map.py.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/gen_pos_map.py
@@ -78,7 +78,7 @@ def GeneratePosMap(third_party_pos_map_file, user_pos_
       result[third_party_pos_name] = mozc_pos
 
   # Create mozc_pos to mozc_pos map.
-  for key, value in user_pos_map.iteritems():
+  for key, value in user_pos_map.items():
     if key in result:
       assert (result[key] == value)
       continue

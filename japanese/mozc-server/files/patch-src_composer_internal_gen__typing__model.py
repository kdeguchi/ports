--- src/composer/internal/gen_typing_model.py.orig	2019-03-04 18:35:55 UTC
+++ src/composer/internal/gen_typing_model.py
@@ -60,8 +60,8 @@ import optparse
 import struct
 
 UNDEFINED_COST = -1
-MAX_UINT16 = struct.unpack('H', '\xFF\xFF')[0]
-MAX_UINT8 = struct.unpack('B', '\xFF')[0]
+MAX_UINT16 = struct.unpack('H', b'\xFF\xFF')[0]
+MAX_UINT8 = struct.unpack('B', b'\xFF')[0]
 
 
 def ParseArgs():
@@ -113,7 +113,7 @@ def GetMappingTable(values, mapping_table_size):
   sorted_values = list(sorted(set(values)))
   mapping_table = sorted_values[0]
   mapping_table_size_without_special_value = mapping_table_size - 1
-  span = len(sorted_values) / (mapping_table_size_without_special_value - 1)
+  span = int(len(sorted_values) / (mapping_table_size_without_special_value - 1))
   mapping_table = [sorted_values[i * span]
                    for i
                    in range(0, mapping_table_size_without_special_value - 1)]
@@ -150,7 +150,7 @@ def GetNearestMappingTableIndex(mapping_table, value):
 
 def GetValueTable(unique_characters, mapping_table, dictionary):
   result = []
-  for key, value in dictionary.iteritems():
+  for key, value in dictionary.items():
     index = GetIndexFromKey(unique_characters, key)
     while len(result) <= index:
       result.append(len(mapping_table) - 1)
@@ -160,20 +160,20 @@ def GetValueTable(unique_characters, mapping_table, di
 
 
 def WriteResult(romaji_transition_cost, output_path):
-  unique_characters = GetUniqueCharacters(romaji_transition_cost.keys())
-  mapping_table = GetMappingTable(romaji_transition_cost.values(),
+  unique_characters = GetUniqueCharacters(list(romaji_transition_cost.keys()))
+  mapping_table = GetMappingTable(list(romaji_transition_cost.values()),
                                   MAX_UINT8 + 1)
   value_list = GetValueTable(unique_characters, mapping_table,
                              romaji_transition_cost)
   with open(output_path, 'wb') as f:
     f.write(struct.pack('<I', len(unique_characters)))
-    f.write(''.join(unique_characters))
+    f.write(''.join(unique_characters).encode())
     offset = 4 + len(unique_characters)
 
     # Add padding to place value list size at 4-byte boundary.
     if offset % 4:
       padding_size = 4 - offset % 4
-      f.write('\x00' * padding_size)
+      f.write(('\x00' * padding_size).encode())
       offset += padding_size
 
     f.write(struct.pack('<I', len(value_list)))
@@ -184,7 +184,7 @@ def WriteResult(romaji_transition_cost, output_path):
     # Add padding to place mapping_table at 4-byte boundary.
     if offset % 4:
       padding_size = 4 - offset % 4
-      f.write('\x00' * padding_size)
+      f.write(('\x00' * padding_size).encode())
       offset += padding_size
 
     for v in mapping_table:

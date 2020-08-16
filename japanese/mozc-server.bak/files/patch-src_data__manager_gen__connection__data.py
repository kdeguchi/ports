--- src/data_manager/gen_connection_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/data_manager/gen_connection_data.py
@@ -32,7 +32,7 @@
 
 __author__ = "hidehiko"
 
-import cStringIO as StringIO
+import io as BytesIO
 import itertools
 import logging
 import optparse
@@ -45,7 +45,7 @@ from build_tools import code_generator_util
 INVALID_COST = 30000
 INVALID_1BYTE_COST = 255
 RESOLUTION_FOR_1BYTE = 64
-FILE_MAGIC = '\xAB\xCD'
+FILE_MAGIC = b'\xAB\xCD'
 
 FALSE_VALUES = ['f', 'false', '0']
 TRUE_VALUES = ['t', 'true', '1']
@@ -79,28 +79,28 @@ def ParseConnectionFile(text_connection_file, pos_size
   # The result is a square matrix.
   mat_size = pos_size + special_pos_size
 
-  matrix = [[0] * mat_size for _ in xrange(mat_size)]
+  matrix = [[0] * mat_size for _ in range(mat_size)]
   with open(text_connection_file) as stream:
     stream = code_generator_util.SkipLineComment(stream)
     # The first line contains the matrix column/row size.
-    size = stream.next().rstrip()
+    size = next(stream).rstrip()
     assert (int(size) == pos_size), '%s != %d' % (size, pos_size)
 
     for array_index, cost in enumerate(stream):
       cost = int(cost.rstrip())
-      rid = array_index / pos_size
+      rid = int(array_index / pos_size)
       lid = array_index % pos_size
       if rid == 0 and lid == 0:
         cost = 0
       matrix[rid][lid] = cost
 
   # Fill INVALID_COST in matrix elements for special POS.
-  for rid in xrange(pos_size, mat_size):
-    for lid in xrange(1, mat_size):  # Skip EOS
+  for rid in range(pos_size, mat_size):
+    for lid in range(1, mat_size):  # Skip EOS
       matrix[rid][lid] = INVALID_COST
 
-  for lid in xrange(pos_size, mat_size):
-    for rid in xrange(1, mat_size):  # Skip BOS
+  for lid in range(pos_size, mat_size):
+    for rid in range(1, mat_size):  # Skip BOS
       matrix[rid][lid] = INVALID_COST
 
   return matrix
@@ -116,7 +116,7 @@ def CreateModeValueList(matrix):
         # Heuristically, we do not compress INVALID_COST.
         continue
       m[cost] = m.get(cost, 0) + 1
-    mode_value = max(m.iteritems(), key=lambda (_, count): count)[0]
+    mode_value = max(iter(m.items()), key=lambda _: _[1])[0]
     result.append(mode_value)
   return result
 
@@ -126,8 +126,8 @@ def CompressMatrixByModeValue(matrix, mode_value_list)
   # list, and fill None into the matrix if it equals to the corresponding
   # mode value.
   assert len(matrix) == len(mode_value_list)
-  for row, mode_value in itertools.izip(matrix, mode_value_list):
-    for index in xrange(len(row)):
+  for row, mode_value in zip(matrix, mode_value_list):
+    for index in range(len(row)):
       if row[index] == mode_value:
         row[index] = None
 
@@ -179,7 +179,7 @@ def BuildBinaryData(matrix, mode_value_list, use_1byte
     resolution = RESOLUTION_FOR_1BYTE
   else:
     resolution = 1
-  stream = StringIO.StringIO()
+  stream = BytesIO.BytesIO()
 
   # Output header.
   stream.write(FILE_MAGIC)
@@ -194,7 +194,7 @@ def BuildBinaryData(matrix, mode_value_list, use_1byte
 
   # 4 bytes alignment.
   if len(mode_value_list) % 2:
-    stream.write('\x00\x00')
+    stream.write('\x00\x00'.encode())
 
   # Process each row:
   for row in matrix:
@@ -237,7 +237,7 @@ def BuildBinaryData(matrix, mode_value_list, use_1byte
       values_size = len(values) * 2
 
     # Output the bits for a row.
-    stream.write(struct.pack('<HH', len(compact_bits) / 8, values_size))
+    stream.write(struct.pack('<HH', int(len(compact_bits) / 8), values_size))
     OutputBitList(chunk_bits, stream)
     OutputBitList(compact_bits, stream)
     if use_1byte_cost:

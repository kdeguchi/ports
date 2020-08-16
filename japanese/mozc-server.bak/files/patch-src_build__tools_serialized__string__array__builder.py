--- src/build_tools/serialized_string_array_builder.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/serialized_string_array_builder.py
@@ -33,7 +33,7 @@
 import struct
 
 
-def SerializeToFile(strings, filename):
+def SerializeToFile(strings_, filename):
   """Builds a binary image of strings.
 
   For file format, see base/serialized_string_array.h.
@@ -42,12 +42,13 @@ def SerializeToFile(strings, filename):
     strings: A list of strings to be serialized.
     filename: Output binary file.
   """
-  array_size = len(strings)
+  array_size = len(strings_)
 
   # Precompute offsets and lengths.
   offsets = []
   lengths = []
   offset = 4 + 8 * array_size  # The start offset of strings chunk
+  strings = list(map(lambda s: s.encode(), strings_))
   for s in strings:
     offsets.append(offset)
     lengths.append(len(s))
@@ -58,11 +59,11 @@ def SerializeToFile(strings, filename):
     f.write(struct.pack('<I', array_size))
 
     # Offset and length array of (4 + 4) * array_size bytes.
-    for i in xrange(array_size):
+    for i in range(array_size):
       f.write(struct.pack('<I', offsets[i]))
       f.write(struct.pack('<I', lengths[i]))
 
     # Strings chunk.
-    for i in xrange(array_size):
+    for i in range(array_size):
       f.write(strings[i])
-      f.write('\0')
+      f.write('\0'.encode())

--- src/build_tools/code_generator_util.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/code_generator_util.py
@@ -46,14 +46,14 @@ def ToCppStringLiteral(s):
     return '"%s"' % s.replace('\\', r'\\').replace('"', r'\"')
   else:
     # One or more characters are non-ascii.
-    return '"%s"' % ''.join(r'\x%02X' % ord(c) for c in s)
+    return '"%s"' % ''.join(r'\x%02X' % c for c in s.encode())
 
 
 def FormatWithCppEscape(format_text, *args):
   """Returns a string filling format with args."""
   literal_list = []
   for arg in args:
-    if isinstance(arg, (types.StringType, types.NoneType)):
+    if isinstance(arg, (bytes, type(None))):
       arg = ToCppStringLiteral(arg)
     literal_list.append(arg)
 
@@ -95,7 +95,7 @@ def WriteCppDataArray(data, variable_name, target_comp
   if target_compiler and target_compiler.startswith('msvs'):
     stream.write('const uint64 k%s_data_wordtype[] = {\n' % variable_name)
 
-    for word_index in xrange(0, len(data), 8):
+    for word_index in range(0, len(data), 8):
       word_chunk = data[word_index:word_index + 8].ljust(8, '\x00')
       stream.write('0x%016X, ' % struct.unpack('<Q', word_chunk))
       if (word_index / 8) % 4 == 3:
@@ -108,17 +108,17 @@ def WriteCppDataArray(data, variable_name, target_comp
         'reinterpret_cast<const char *>(k%s_data_wordtype);\n' % (
             variable_name, variable_name))
   else:
-    stream.write('const char k%s_data[] =\n' % variable_name)
+    stream.write(('const char k%s_data[] =\n' % variable_name).encode())
     # Output 16bytes per line.
     chunk_size = 16
-    for index in xrange(0, len(data), chunk_size):
+    for index in range(0, len(data), chunk_size):
       chunk = data[index:index + chunk_size]
-      stream.write('"')
-      stream.writelines(r'\x%02X' % ord(c) for c in chunk)
-      stream.write('"\n')
-    stream.write(';\n')
+      stream.write('"'.encode())
+      stream.writelines(br'\x%02X' % c for c in chunk)
+      stream.write('"\n'.encode())
+    stream.write(';\n'.encode())
 
-  stream.write('const size_t k%s_size = %d;\n' % (variable_name, len(data)))
+  stream.write(('const size_t k%s_size = %d;\n' % (variable_name, len(data))).encode())
 
 
 def ToJavaStringLiteral(codepoint_list):
@@ -129,7 +129,7 @@ def ToJavaStringLiteral(codepoint_list):
     return 'null'
   result = r'"'
   for codepoint in codepoint_list:
-    utf16_string = unichr(codepoint).encode('utf-16be')
+    utf16_string = chr(codepoint).encode('utf-16be')
     if len(utf16_string) == 2:
       (u0, l0) = utf16_string
       result += r'\u%02X%02X' % (ord(u0), ord(l0))
@@ -172,5 +172,5 @@ def SplitChunk(iterable, n):
   grouper extends the last chunk to make it an n-element chunk by adding
   appropriate value, but this returns truncated chunk.
   """
-  for index in xrange(0, len(iterable), n):
+  for index in range(0, len(iterable), n):
     yield iterable[index:index + n]

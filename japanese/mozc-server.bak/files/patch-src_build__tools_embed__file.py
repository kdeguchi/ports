--- src/build_tools/embed_file.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/embed_file.py
@@ -46,33 +46,33 @@ def _ParseOption():
 
 def _FormatAsUint64LittleEndian(s):
   """Formats a string as uint64 value in little endian order."""
-  for _ in xrange(len(s), 8):
-    s += '\0'
+  for _ in range(len(s), 8):
+    s += '\0'.encode()
   s = s[::-1]  # Reverse the string
-  return '0x%s' % binascii.b2a_hex(s)
+  return '0x%s' % binascii.b2a_hex(s).decode()
 
 
 def main():
   opts = _ParseOption()
   with open(opts.input, 'rb') as infile:
     with open(opts.output, 'wb') as outfile:
-      outfile.write(
+      outfile.write((
           '#ifdef MOZC_EMBEDDED_FILE_%(name)s\n'
           '#error "%(name)s was already included or defined elsewhere"\n'
           '#else\n'
           '#define MOZC_EMBEDDED_FILE_%(name)s\n'
           'const uint64 %(name)s_data[] = {\n'
-          % {'name': opts.name})
+          % {'name': opts.name}).encode())
 
       while True:
         chunk = infile.read(8)
         if not chunk:
           break
-        outfile.write('  ')
-        outfile.write(_FormatAsUint64LittleEndian(chunk))
-        outfile.write(',\n')
+        outfile.write('  '.encode())
+        outfile.write(_FormatAsUint64LittleEndian(chunk).encode())
+        outfile.write(',\n'.encode())
 
-      outfile.write(
+      outfile.write((
           '};\n'
           'const EmbeddedFile %(name)s = {\n'
           '  %(name)s_data,\n'
@@ -80,7 +80,7 @@ def main():
           '};\n'
           '#endif  // MOZC_EMBEDDED_FILE_%(name)s\n'
           % {'name': opts.name,
-             'size': os.stat(opts.input).st_size})
+             'size': os.stat(opts.input).st_size}).encode())
 
 
 if __name__ == '__main__':

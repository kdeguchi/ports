--- src/gui/character_pad/data/gen_unicode_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/gui/character_pad/data/gen_unicode_data.py
@@ -47,17 +47,17 @@ def main():
     if code < 0x2FFFF:
       results.append("  { %d, \"%s\" }," % (code, desc))
 
-  print "struct UnicodeData {";
-  print "  char32 ucs4;";
-  print "  const char *description;";
-  print "};";
-  print ""
-  print "static const size_t kUnicodeDataSize = %d;" % (len(results))
-  print "static const UnicodeData kUnicodeData[] = {";
+  print("struct UnicodeData {");
+  print("  char32 ucs4;");
+  print("  const char *description;");
+  print("};");
+  print("")
+  print("static const size_t kUnicodeDataSize = %d;" % (len(results)))
+  print("static const UnicodeData kUnicodeData[] = {");
   for line in results:
-    print line;
-  print "  { 0, NULL }";
-  print "};";
+    print(line);
+  print("  { 0, NULL }");
+  print("};");
 
 if __name__ == "__main__":
   main()

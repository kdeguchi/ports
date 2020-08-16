--- src/gui/character_pad/data/gen_unihan_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/gui/character_pad/data/gen_unihan_data.py
@@ -43,12 +43,12 @@ def Escape(n):
 
 def GetCode(n):
   if n is not "NULL":
-    n = string.replace(n, '0-', 'JIS X 0208: 0x')
-    n = string.replace(n, '1-', 'JIS X 0212: 0x')
-    n = string.replace(n, '3-', 'JIS X 0213: 0x')
-    n = string.replace(n, '4-', 'JIS X 0213: 0x')
-    n = string.replace(n, 'A-', 'Vendors Ideographs: 0x')
-    n = string.replace(n, '3A', 'JIS X 0213 2000: 0x')
+    n = n.replace('0-', 'JIS X 0208: 0x')
+    n = n.replace('1-', 'JIS X 0212: 0x')
+    n = n.replace('3-', 'JIS X 0213: 0x')
+    n = n.replace('4-', 'JIS X 0213: 0x')
+    n = n.replace('A-', 'Vendors Ideographs: 0x')
+    n = n.replace('3A', 'JIS X 0213 2000: 0x')
     return "\"%s\"" % n
   else:
     return "NULL"
@@ -59,7 +59,7 @@ def GetRadical(n):
     m = pat.match(n)
     if m:
       result = rs[m.group(1)]
-      return  "\"%s\"" % (result.encode('string_escape'))
+      return  "\"%s\"" % (''.join(r'\x%02x' % c for c in result.encode()))
     else:
       return "NULL"
   else:
@@ -89,20 +89,20 @@ def main():
 
   keys = sorted(dic.keys())
 
-  print "struct UnihanData {";
-  print "  unsigned int ucs4;";
+  print("struct UnihanData {");
+  print("  unsigned int ucs4;");
 # Since the total strokes defined in Unihan data is Chinese-based
 # number, we can't use it.
-#  print "  unsigned char total_strokes;";
-  print "  const char *japanese_kun;";
-  print "  const char *japanese_on;";
+#  print("  unsigned char total_strokes;");
+  print("  const char *japanese_kun;");
+  print("  const char *japanese_on;");
 # Since the radical information defined in Unihan data is Chinese-based
 # number, we can't use it.
-#  print "  const char *radical;";
-  print "  const char *IRG_jsource;";
-  print "};"
-  print "static const size_t kUnihanDataSize = %d;" % (len(keys))
-  print "static const UnihanData kUnihanData[] = {"
+#  print("  const char *radical;");
+  print("  const char *IRG_jsource;");
+  print("};")
+  print("static const size_t kUnihanDataSize = %d;" % (len(keys)))
+  print("static const UnihanData kUnihanData[] = {")
 
   for key in keys:
     total_strokes = dic[key].get("kTotalStrokes", "0")
@@ -110,10 +110,10 @@ def main():
     on =  Escape(dic[key].get("kJapaneseOn", "NULL"))
     rad = GetRadical(dic[key].get("kRSUnicode", "NULL"))
     code = GetCode(dic[key].get("kIRG_JSource", "NULL"))
-#    print " { 0x%s, %s, %s, %s, %s, %s }," % (key, total_strokes, kun, on, rad, code)
-    print " { 0x%s, %s, %s, %s }," % (key, kun, on, code)
+#    print(" { 0x%s, %s, %s, %s, %s, %s }," % (key, total_strokes, kun, on, rad, code))
+    print(" { 0x%s, %s, %s, %s }," % (key, kun, on, code))
 
-  print "};"
+  print("};")
 
 if __name__ == "__main__":
   main()

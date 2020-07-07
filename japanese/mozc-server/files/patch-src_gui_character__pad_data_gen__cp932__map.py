--- src/gui/character_pad/data/gen_cp932_map.py.orig	2019-03-04 18:35:55 UTC
+++ src/gui/character_pad/data/gen_cp932_map.py
@@ -44,7 +44,7 @@ def main():
   for line in fh.readlines():
     if line[0] is '#':
       continue
-    array = string.split(line)
+    array = line.split()
     sjis = array[0]
     ucs2 = array[1]
     if eval(sjis) < 32 or not IsValidUnicode(ucs2):
@@ -53,17 +53,17 @@ def main():
 
   keys = sorted(result.keys())
 
-  print "struct CP932MapData {"
-  print "  unsigned int ucs4;"
-  print "  unsigned short int sjis;"
-  print "};"
-  print ""
-  print "static const size_t kCP932MapDataSize = %d;" % (len(keys))
-  print "static const CP932MapData kCP932MapData[] = {"
+  print("struct CP932MapData {")
+  print("  unsigned int ucs4;")
+  print("  unsigned short int sjis;")
+  print("};")
+  print("")
+  print("static const size_t kCP932MapDataSize = %d;" % (len(keys)))
+  print("static const CP932MapData kCP932MapData[] = {")
   for n in keys:
-    print "  { %s, %s }," % (n ,result[n])
-  print "  { 0, 0 }";
-  print "};"
+    print("  { %s, %s }," % (n ,result[n]))
+  print("  { 0, 0 }");
+  print("};")
 
 if __name__ == "__main__":
   main()

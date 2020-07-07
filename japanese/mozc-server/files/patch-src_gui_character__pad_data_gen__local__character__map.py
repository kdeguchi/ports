--- src/gui/character_pad/data/gen_local_character_map.py.orig	2019-03-04 18:35:55 UTC
+++ src/gui/character_pad/data/gen_local_character_map.py
@@ -45,7 +45,7 @@ def LoadJISX0201(filename):
   for line in fh.readlines():
     if line[0] is '#':
       continue
-    array = string.split(line)
+    array = line.split()
     jis = array[0].replace('0x', '')
     ucs2 = array[1].replace('0x', '')
     if len(jis) == 2:
@@ -106,13 +106,13 @@ def LoadCP932(filename):
 def Output(arg):
   name = arg[0]
   result = arg[1]
-  print "static const size_t k%sMapSize = %d;" % (name, len(result))
-  print "static const mozc::gui::CharacterPalette::LocalCharacterMap k%sMap[] = {" % (name)
+  print("static const size_t k%sMapSize = %d;" % (name, len(result)))
+  print("static const mozc::gui::CharacterPalette::LocalCharacterMap k%sMap[] = {" % (name))
   for n in result:
-    print "  { 0x%s, 0x%s }," % (n[0] ,n[1])
-  print "  { 0, 0 }";
-  print "};"
-  print ""
+    print("  { 0x%s, 0x%s }," % (n[0] ,n[1]))
+  print("  { 0, 0 }");
+  print("};")
+  print("")
 
 if __name__ == "__main__":
   Output(LoadJISX0201(sys.argv[1]))

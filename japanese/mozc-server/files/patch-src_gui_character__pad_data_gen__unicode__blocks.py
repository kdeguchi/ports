--- src/gui/character_pad/data/gen_unicode_blocks.py.orig	2019-03-04 18:35:55 UTC
+++ src/gui/character_pad/data/gen_unicode_blocks.py
@@ -36,7 +36,7 @@ import re
 re = re.compile('^(.....?)\.\.(.....?); (.+)')
 
 def main():
-  print "static const mozc::gui::CharacterPalette::UnicodeBlock kUnicodeBlockTable[] = {"
+  print("static const mozc::gui::CharacterPalette::UnicodeBlock kUnicodeBlockTable[] = {")
   fh = open(sys.argv[1])
   for line in fh.readlines():
     if line[0] is '#':
@@ -47,11 +47,11 @@ def main():
       end   = int(m.group(2), 16)
       name = m.group(3)
       if start <= 0x2FFFF and end <= 0x2FFFF:
-        print "  { \"%s\", { %d, %d } }," % (name, start, end)
+        print("  { \"%s\", { %d, %d } }," % (name, start, end))
 
-  print "  { NULL, { 0, 0 } }"
-  print "};"
-  print ""
+  print("  { NULL, { 0, 0 } }")
+  print("};")
+  print("")
 
 if __name__ == "__main__":
   main()

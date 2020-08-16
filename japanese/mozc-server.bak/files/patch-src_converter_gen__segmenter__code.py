--- src/converter/gen_segmenter_code.py.orig	2019-03-04 18:35:55 UTC
+++ src/converter/gen_segmenter_code.py
@@ -79,7 +79,7 @@ def GetRange(pos, pattern, name):
   pat = re.compile(PatternToRegexp(pattern))
   min = -1;
   max = -1;
-  keys = pos.keys()
+  keys = list(pos.keys())
   keys.sort()
 
   range = []
@@ -107,7 +107,7 @@ def GetRange(pos, pattern, name):
       tmp.append("(%s >= %s && %s <= %s)" % (name, r[0], name, r[1]))
 
   if len(tmp) == 0:
-    print "FATAL: No rule fiind %s" % (pattern)
+    print("FATAL: No rule fiind %s" % (pattern))
     sys.exit(-1)
 
   return " || ".join(tmp)
@@ -115,7 +115,7 @@ def GetRange(pos, pattern, name):
 def main():
   pos = ReadPOSID(sys.argv[1], sys.argv[2])
 
-  print HEADER % (len(pos.keys()), len(pos.keys()))
+  print(HEADER % (len(pos.keys()), len(pos.keys())))
 
   for line in open(sys.argv[3], "r"):
     if len(line) <= 1 or line[0] == '#':
@@ -124,10 +124,10 @@ def main():
     result = result.lower()
     lcond = GetRange(pos, l, "rid") or "true";
     rcond = GetRange(pos, r, "lid") or "true";
-    print "  // %s %s %s" % (l, r, result)
-    print "  if ((%s) && (%s)) { return %s; }" % (lcond, rcond, result)
+    print("  // %s %s %s" % (l, r, result))
+    print("  if ((%s) && (%s)) { return %s; }" % (lcond, rcond, result))
 
-  print FOOTER
+  print(FOOTER)
 
 if __name__ == "__main__":
   main()

--- src/dictionary/gen_zip_code_seed.py.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/gen_zip_code_seed.py
@@ -83,7 +83,7 @@ class ZipEntry(object):
     address = unicodedata.normalize('NFKC', self.address)
     line = '\t'.join([zip_code, '0', '0', str(ZIP_CODE_COST),
                       address, ZIP_CODE_LABEL])
-    print line.encode('utf-8')
+    print(line)
 
 
 def ProcessZipCodeCSV(file_name):

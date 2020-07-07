--- src/dictionary/zip_code_util.py.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/zip_code_util.py
@@ -38,7 +38,7 @@ def ReadCSV(file_name):
   # Do not use csv reader module because it does not support unicode
   return [GetCells(line) for line in codecs.open(file_name,
                                                  'r',
-                                                 'shift_jis',
+                                                 'cp932',
                                                  errors='replace')]
 
 

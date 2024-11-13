--- merge_dictionaries.py.orig	2024-10-26 03:10:07.000000000 +0900
+++ merge_dictionaries.py	2024-10-26 09:32:37.793968000 +0900
@@ -7,18 +7,14 @@
 import gzip
 import subprocess
 import sys
-import urllib.request
 from unicodedata import normalize
 
 
 def get_id_mozc():
     # Mozc の一般名詞のIDを取得
-    url = 'https://raw.githubusercontent.com/' + \
-            'google/mozc/master/src/data/dictionary_oss/id.def'
+    id_def = open("id.def", "r")
+    id_mozc = id_def.read()

-    with urllib.request.urlopen(url) as response:
-        id_mozc = response.read().decode()
-
     id_mozc = id_mozc.split(' 名詞,一般,')[0].split('\n')[-1]
     return (id_mozc)
 
@@ -62,10 +58,6 @@
 
 def count_word_hits():
     # jawiki-latest-all-titles を取得
-    subprocess.run(
-        ['wget', '-N', 'https://dumps.wikimedia.org/jawiki/latest/' +
-            'jawiki-latest-all-titles-in-ns0.gz'], check=True)
-
     with gzip.open(
             'jawiki-latest-all-titles-in-ns0.gz', 'rt',
             encoding='utf-8') as file:

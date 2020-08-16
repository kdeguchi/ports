--- src/prediction/gen_zero_query_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/prediction/gen_zero_query_data.py
@@ -66,7 +66,7 @@ def ParseCodePoint(s):
 
 def NormalizeString(string):
   return unicodedata.normalize(
-      'NFKC', string.decode('utf-8')).encode('utf-8').replace('~', '〜')
+      'NFKC', string).replace('~', '〜')
 
 
 def RemoveTrailingNumber(string):
@@ -84,7 +84,7 @@ def GetReadingsFromDescription(description):
   #  - ビル・建物
   # \xE3\x83\xBB : "・"
   return [RemoveTrailingNumber(token) for token
-          in re.split(r'(?:\(|\)|/|\xE3\x83\xBB)+', normalized)]
+          in re.split(r'(?:\(|\)|/|・)+', normalized)]
 
 
 def ReadEmojiTsv(stream):
@@ -119,7 +119,7 @@ def ReadEmojiTsv(stream):
 
     reading_list = []
     # \xe3\x80\x80 is a full-width space
-    for reading in re.split(r'(?: |\xe3\x80\x80)+', NormalizeString(readings)):
+    for reading in re.split(r'(?: |　)+', NormalizeString(readings)):
       if not reading:
         continue
       reading_list.append(reading)
@@ -147,7 +147,7 @@ def ReadEmojiTsv(stream):
                               emoji, emoji_type, android_pua))
 
   # Sort emoji for each reading.
-  for key in zero_query_dict.keys():
+  for key in list(zero_query_dict.keys()):
     zero_query_dict[key].sort(key=lambda e: (e.value, e.emoji_android_pua))
 
   return zero_query_dict
@@ -188,7 +188,7 @@ def ReadEmoticonTsv(stream):
     readings = columns[2]
 
     # \xe3\x80\x80 is a full-width space
-    for reading in re.split(r'(?: |\xe3\x80\x80)+', readings.strip()):
+    for reading in re.split(r'(?: |　)+', readings.strip()):
       if not reading:
         continue
       zero_query_dict[reading].append(
@@ -210,7 +210,7 @@ def ReadSymbolTsv(stream):
     symbol = columns[1]
     readings = columns[2]
 
-    symbol_unicode = symbol.decode('utf-8')
+    symbol_unicode = symbol #.decode('utf-8')
     if len(symbol_unicode) != 1:
       continue
 
@@ -222,7 +222,7 @@ def ReadSymbolTsv(stream):
       continue
 
     # \xe3\x80\x80 is a full-width space
-    for reading in re.split(r'(?: |\xe3\x80\x80)+', readings.strip()):
+    for reading in re.split(r'(?: |　)+', readings.strip()):
       if not reading:
         continue
       zero_query_dict[reading].append(
@@ -254,10 +254,10 @@ def IsValidKeyForZeroQuery(key):
 def MergeZeroQueryData(rule_dict, symbol_dict, emoji_dict, emoticon_dict):
   """Returnes merged zero query data."""
   merged = defaultdict(list)
-  for key in rule_dict.keys():
+  for key in list(rule_dict.keys()):
     merged[key].extend(rule_dict[key])
 
-  for key in emoji_dict.keys():
+  for key in list(emoji_dict.keys()):
     if not IsValidKeyForZeroQuery(key):
       continue
     # Skips aggressive emoji candidates.
@@ -266,14 +266,14 @@ def MergeZeroQueryData(rule_dict, symbol_dict, emoji_d
       continue
     merged[key].extend(emoji_dict[key])
 
-  for key in emoticon_dict.keys():
+  for key in list(emoticon_dict.keys()):
     if not IsValidKeyForZeroQuery(key):
       continue
     # Merges only up to 3 emoticons.
     # Example: "にこにこ" have many candidates.
     merged[key].extend(emoticon_dict[key][:3])
 
-  for key in symbol_dict.keys():
+  for key in list(symbol_dict.keys()):
     if not IsValidKeyForZeroQuery(key):
       continue
     # Skip aggressive emoji candidates.

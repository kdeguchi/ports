--- src/rewriter/gen_emoji_rewriter_data.py.orig	2019-03-04 18:35:55 UTC
+++ src/rewriter/gen_emoji_rewriter_data.py
@@ -79,14 +79,13 @@ def ParseCodePoint(s):
   return int(s, 16)
 
 
-_FULLWIDTH_RE = re.compile(ur'[！-～]')   # U+FF01 - U+FF5E
+_FULLWIDTH_RE = re.compile(r'[！-～]')   # U+FF01 - U+FF5E
 
 
 def NormalizeString(string):
   """Normalize full width ascii characters to half width characters."""
-  offset = ord(u'Ａ') - ord(u'A')
-  return _FULLWIDTH_RE.sub(lambda x: unichr(ord(x.group(0)) - offset),
-                           unicode(string, 'utf-8')).encode('utf-8')
+  offset = ord('Ａ') - ord('A')
+  return _FULLWIDTH_RE.sub(lambda x: chr(ord(x.group(0)) - offset), string)
 
 
 def ReadEmojiTsv(stream):
@@ -159,7 +158,7 @@ def ReadEmojiTsv(stream):
 def OutputData(emoji_data_list, token_dict,
                token_array_file, string_array_file):
   """Output token and string arrays to files."""
-  sorted_token_dict = sorted(token_dict.iteritems())
+  sorted_token_dict = sorted(token_dict.items())
 
   strings = {}
   for reading, _ in sorted_token_dict:
@@ -171,7 +170,7 @@ def OutputData(emoji_data_list, token_dict,
     strings[docomo_description] = 0
     strings[softbank_description] = 0
     strings[kddi_description] = 0
-  sorted_strings = sorted(strings.iterkeys())
+  sorted_strings = sorted(strings.keys())
   for index, s in enumerate(sorted_strings):
     strings[s] = index
 

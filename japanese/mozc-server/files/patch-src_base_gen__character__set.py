--- src/base/gen_character_set.py.orig	2019-03-04 18:35:55 UTC
+++ src/base/gen_character_set.py
@@ -250,7 +250,7 @@ def GenerateCategoryBitmap(category_list, name):
   # (at most) four code points.
   bit_list = []
   for _, group in itertools.groupby(enumerate(category_list),
-                                    lambda (codepoint, _): codepoint / 4):
+                                    lambda codepoint: int(codepoint[0] / 4)):
     # Fill bits from LSB to MSB for each group.
     bits = 0
     for index, (_, category) in enumerate(group):
@@ -263,7 +263,7 @@ def GenerateCategoryBitmap(category_list, name):
 
   # Output the content. Each line would have (at most) 16 bytes.
   for _, group in itertools.groupby(enumerate(bit_list),
-                                    lambda (index, _): index / 16):
+                                    lambda index: int(index[0] / 16)):
     line = ['    \"']
     for _, bits in group:
       line.append('\\x%02X' % bits)
@@ -386,7 +386,7 @@ def GenerateGetCharacterSet(category_list, bitmap_name
   # Bitmap lookup.
   # TODO(hidehiko): the bitmap has two huge 0-bits ranges. Reduce them.
   category_map = [
-      (bits, category) for category, bits in CATEGORY_BITMAP.iteritems()]
+      (bits, category) for category, bits in CATEGORY_BITMAP.items()]
   category_map.sort()
 
   lines.extend([
@@ -451,7 +451,7 @@ def main():
                                      options.jisx0213file)
   category_list = [
       categorizer.GetCategory(codepoint)
-      for codepoint in xrange(categorizer.MaxCodePoint() + 1)]
+      for codepoint in range(categorizer.MaxCodePoint() + 1)]
   generated_character_set_header = GenerateCharacterSetHeader(category_list)
 
   # Write the result.

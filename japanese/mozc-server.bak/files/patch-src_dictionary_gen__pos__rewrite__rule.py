--- src/dictionary/gen_pos_rewrite_rule.py.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/gen_pos_rewrite_rule.py
@@ -112,7 +112,7 @@ def main():
     ids.append(id)
 
   with open(opts.output, 'wb') as f:
-    f.write(''.join(chr(id) for id in ids))
+    f.write((''.join(chr(id) for id in ids)).encode())
 
 
 if __name__ == '__main__':

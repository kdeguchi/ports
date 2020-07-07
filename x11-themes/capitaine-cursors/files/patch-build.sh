--- build.sh.orig	2020-02-20 02:12:38 UTC
+++ build.sh
@@ -151,7 +151,7 @@ function assemble {
 
     if [ -e "$to" ]; then continue; fi
 
-    ln -sr "$from" "$to"
+    ln -s "$from" "$to"
   done < "$ALIASES"
   popd > /dev/null || return 1
 

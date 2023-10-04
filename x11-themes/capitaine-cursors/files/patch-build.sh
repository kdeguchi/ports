--- build.sh.orig	2020-02-23 19:43:04 UTC
+++ build.sh
@@ -136,11 +136,11 @@ function assemble {
   BASE_DIR="$DIST/$variant"
   OUTPUT_DIR="$BASE_DIR/cursors"
   INDEX_FILE="$BASE_DIR/index.theme"
-  THEME_NAME="Capitaine Cursors"
+  THEME_NAME="Capitaine-Cursors"
 
   case "$variant" in
     dark) THEME_NAME="$THEME_NAME" ;;
-    light) THEME_NAME="$THEME_NAME - White" ;;
+    light) THEME_NAME="$THEME_NAME-White" ;;
     *) exit 1 ;;
   esac
 

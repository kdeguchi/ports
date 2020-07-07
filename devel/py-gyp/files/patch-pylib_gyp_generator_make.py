--- pylib/gyp/generator/make.py.orig	2020-05-03 23:41:18 UTC
+++ pylib/gyp/generator/make.py
@@ -367,7 +367,7 @@ sed -e "s|^$(notdir $@)|$@|" $(depfile).raw >> $(depfi
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
+env NL=`printf "\n"` sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
   grep -v '^$$'                             |\
   sed -e 1d -e 's|$$|:|'                     \
     >> $(depfile)

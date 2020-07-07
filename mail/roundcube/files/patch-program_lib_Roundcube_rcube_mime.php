--- program/lib/Roundcube/rcube_mime.php.orig	2020-04-26 19:50:08 UTC
+++ program/lib/Roundcube/rcube_mime.php
@@ -591,6 +591,9 @@ class rcube_mime
         // Note: Never try to use iconv instead of mbstring functions here
         //       Iconv's substr/strlen are 100x slower (#1489113)
 
+        if (isset(rcube_charset::$mb_aliases[$charset])) {
+            $charset = rcube_charset::$mb_aliases[$charset];
+        }
         if ($charset && $charset != RCUBE_CHARSET) {
             mb_internal_encoding($charset);
         }

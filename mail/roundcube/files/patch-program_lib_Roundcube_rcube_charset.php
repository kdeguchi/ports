--- program/lib/Roundcube/rcube_charset.php.orig	2020-04-26 19:50:08 UTC
+++ program/lib/Roundcube/rcube_charset.php
@@ -171,6 +171,12 @@ class rcube_charset
         65001 => 'UTF-8',
     );
 
+    static public $mb_aliases = array(
+        'WINDOWS-1257' => 'ISO-8859-13',
+        'US-ASCII'     => 'ASCII',
+        'ISO-2022-JP'  => 'ISO-2022-JP-MS',
+    );
+
     /**
      * Catch an error and throw an exception.
      *
@@ -307,7 +313,7 @@ class rcube_charset
 
         // convert charset using iconv module
         if ($iconv_options !== false && $from != 'UTF7-IMAP' && $to != 'UTF7-IMAP'
-            && $from !== 'ISO-2022-JP'
+            && $from !== 'ISO-2022-JP' && $to !== 'ISO-2022-JP'
         ) {
             // throw an exception if iconv reports an illegal character in input
             // it means that input string has been truncated
@@ -331,11 +337,7 @@ class rcube_charset
 
         // convert charset using mbstring module
         if ($mbstring_sc !== false) {
-            $aliases = array(
-                'WINDOWS-1257' => 'ISO-8859-13',
-                'US-ASCII'     => 'ASCII',
-                'ISO-2022-JP'  => 'ISO-2022-JP-MS',
-            );
+            $aliases = self::$mb_aliases;
 
             $mb_from = $aliases[$from] ?: $from;
             $mb_to   = $aliases[$to] ?: $to;

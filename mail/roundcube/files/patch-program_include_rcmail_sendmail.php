--- program/include/rcmail_sendmail.php.orig	2020-04-26 19:50:08 UTC
+++ program/include/rcmail_sendmail.php
@@ -672,6 +672,10 @@ class rcmail_sendmail
      */
     public function email_input_format($mailto, $count = false, $check = true)
     {
+        // convert to UTF-8 to preserve \x2c(,) and \x3b(;) used in ISO-2022-JP;
+        $charset = $this->options['charset'];
+        $mailto = rcube_charset::convert($mailto, $charset, RCUBE_CHARSET);
+
         // simplified email regexp, supporting quoted local part
         $email_regexp = '(\S+|("[^"]+"))@\S+';
 
@@ -703,7 +707,21 @@ class rcmail_sendmail
                 if ($name[0] == '"' && $name[strlen($name)-1] == '"') {
                     $name = substr($name, 1, -1);
                 }
-                $name     = stripcslashes($name);
+                // encode "name" field.
+                if (function_exists('mb_encode_mimeheader') && $this->rcmail->config->get('head_encoding_base64')) {
+                    $head_encoding_mode = 'B';
+                    $name = rcube_charset::convert($name, RCUBE_CHARSET, $charset);
+                    $mb_charset = $charset;
+                    if (rcube_charset::$mb_aliases[$charset]) {
+                        $mb_charset = rcube_charset::$mb_aliases[$charset];
+                    }
+                    mb_internal_encoding($mb_charset);
+                    $name = preg_replace('/^"(.*)"$/', '$1', $name);
+                    $name = mb_encode_mimeheader($name, $mb_charset, $head_encoding_mode, "\r\n", 8);
+                    mb_internal_encoding(RCUBE_CHARSET);
+                } else {
+                    $name = stripcslashes($name);
+                }
                 $address  = rcube_utils::idn_to_ascii(trim($address, '<>'));
                 $result[] = format_email_recipient($address, $name);
                 $item     = $address;

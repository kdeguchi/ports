--- text.c.orig	2011-06-28 02:04:59 UTC
+++ text.c
@@ -18,6 +18,9 @@
  * @(#)$Header: /mm2/home/cvs/bc-src/tgif/text.c,v 1.73 2011/06/14 02:32:19 william Exp $
  */
 
+#include <iconv.h>
+#include <string.h>
+
 #define _INCLUDE_FROM_TEXT_C_
 
 #include "tgifdefs.h"
@@ -3846,6 +3849,9 @@ int HandleDoubleByteUTF8Chars(s, has_ch)
 
 static XComposeStatus c_stat;
 
+static char *locale = NULL;
+static iconv_t convd = NULL;
+
 void DrawText(input)
    XEvent *input;
 {
@@ -3922,6 +3928,31 @@ void DrawText(input)
             CalcSingleByteInfoForCopyUTF8(NULL);
          }
       }
+      if(locale == NULL){
+         locale = setlocale(LC_CTYPE, NULL);
+         if(locale == NULL) locale = "C";
+         if(strncmp(locale, "ja_JP.", 6) == 0 &&
+            (strncasecmp(locale+6, "utf8", 4) == 0 ||
+             strncasecmp(locale+6, "utf-8", 5) == 0)){
+            convd = iconv_open("EUC-JP", "utf-8");
+         }
+      }
+      if(convd != NULL){
+         size_t ret;
+         char s2[80];
+         char *in_buf, *out_buf;
+         size_t in_size, out_size;
+         iconv(convd, NULL, NULL, NULL, NULL);
+         in_buf = s;
+         in_size = strlen(s);
+         out_buf = s2;
+         out_size = sizeof(s2) - 1;
+         ret = iconv(convd, &in_buf, &in_size, &out_buf, &out_size);
+         if(ret >= 0){
+            memcpy(s, s2, sizeof(s2)-1 - out_size);
+            s[sizeof(s2)-1 - out_size] = 0;
+         }
+      }
       HandleTextFromBuffer(key_ev, s, key_sym, has_ch);
    }
 }
@@ -4017,7 +4048,7 @@ void DumpOneStr(FP, FontIndex, DoubleByte, DoubleByteM
          }
          if (((*Str) & 0x80) != '\0') {
             if (DoubleByteModBytes) {
-               if (fprintf(FP, "\\%03o\\%03o", Str[0]&0x7f, Str[1]&0x7f) == EOF) {
+               if (fprintf(FP, "\\%03o\\%03o", Str[0]&0xff, Str[1]&0xff) == EOF) {
                   writeFileFailed = TRUE;
                }
             } else {

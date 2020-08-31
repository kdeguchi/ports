--- font.c.orig	2011-06-28 02:04:57 UTC
+++ font.c
@@ -192,7 +192,7 @@ static int	defaultCurSzUnit=(-1);
 static int	defaultCurStyle=(-1);
 
 static char	*initSizeMenuStr[] = {
-      "8", "10", "11", "12", "14", "17", "18", "20", "24", "25", "34"
+  "8", "10", "11", "12", "14", "17", "18", "20", "22", "24", "25", "34"
 };
 char	**fontMenuStr=NULL;
 char	*defFontMenuStr[] = {
@@ -256,9 +256,9 @@ static char	*initFontInfoStr[]={
    "new century schoolbook-bold-i-normal", "iso8859-1",
          "NewCenturySchlbk-BoldItalic",
    "*symbol*-medium-r-normal", "adobe-fontspecific", "Symbol",
-   "*symbol*-medium-r-normal", "adobe-fontspecific", "Symbol",
-   "*symbol*-medium-r-normal", "adobe-fontspecific", "Symbol",
-   "*symbol*-medium-r-normal", "adobe-fontspecific", "Symbol",
+   "*symbol*-bold-r-normal", "adobe-fontspecific", "Symbol-Bold",
+   "*symbol*-medium-o-normal", "adobe-fontspecific", "Symbol-Oblique",
+   "*symbol*-bold-o-normal", "adobe-fontspecific", "Symbol-BoldOblique",
    NULL, NULL, NULL
 };
 
@@ -1058,10 +1058,10 @@ void MyTextExtents(xfs, pszStr, nLen, pxcs)
                   (nOdd || ((*psz)&0x80) == nDoubleByte);
                   psz++, nSubStrIndex++) {
                if (nOdd) {
-                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz) & 0x7f;
                   nDoubleByteIndex++;
                } else {
-                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz) & 0x7f;
                }
                nOdd = !nOdd;
             }
@@ -1121,10 +1121,10 @@ int MyTextWidth(xfs, pszStr, nLen)
                   (nOdd || ((*psz)&0x80) == nDoubleByte);
                   psz++, nSubStrIndex++) {
                if (nOdd) {
-                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz) & 0x7f;
                   nDoubleByteIndex++;
                } else {
-                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz) & 0x7f;
                }
                nOdd = !nOdd;
             }
@@ -1170,10 +1170,10 @@ void MyDrawString(dpy, d, gc, nDepth, x, y, pszStr, nL
                   (nOdd || ((*psz)&0x80) == nDoubleByte);
                   psz++, nSubStrIndex++) {
                if (nOdd) {
-                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz) & 0x7f;
                   nDoubleByteIndex++;
                } else {
-                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz) & 0x7f;
                }
                nOdd = !nOdd;
             }

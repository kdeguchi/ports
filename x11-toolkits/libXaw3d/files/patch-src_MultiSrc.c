--- src/MultiSrc.c.orig	2022-08-15 23:39:34 UTC
+++ src/MultiSrc.c
@@ -964,15 +964,18 @@ static Boolean
 WriteToFile(String string, String name)
 {
   int fd;
+  Bool result = True;
 
-  if ( ((fd = creat(name, 0666)) == -1 ) ||
-       (write(fd, string, sizeof(unsigned char) * strlen(string)) == -1) )
+  if ((fd = creat(name, 0666)) == -1)
     return(FALSE);
 
+  if (write(fd, string, sizeof(unsigned char) * strlen(string)) == -1)
+    result = False;
+
   if ( close(fd) == -1 )
     return(FALSE);
 
-  return(TRUE);
+  return(result);
 }
 
 

--- include/X11/Xaw3d/List.h.orig	2018-06-19 05:00:59 UTC
+++ include/X11/Xaw3d/List.h
@@ -181,7 +181,7 @@ _XFUNCPROTOBEGIN
 
 extern void XawListChange(
     Widget		/* w */,
-    String*		/* list */,
+    char**		/* list */,
     int			/* nitems */,
     int			/* longest */,
 #if NeedWidePrototypes

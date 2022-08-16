--- src/AsciiSrc.c.orig	2018-06-19 05:00:59 UTC
+++ src/AsciiSrc.c
@@ -111,7 +111,7 @@ static void Initialize(Widget, Widget, ArgList, Cardin
 static void Destroy(Widget);
 static void GetValuesHook(Widget, ArgList, Cardinal *);
 static String MyStrncpy(char *, char *, int);
-static String StorePiecesInString(AsciiSrcObject);
+static char * StorePiecesInString(AsciiSrcObject);
 static Boolean SetValues(Widget, Widget, Widget, ArgList, Cardinal *);
 static Boolean WriteToFile(_Xconst _XtString, _Xconst _XtString);
 
@@ -923,10 +923,10 @@ WriteToFile(_Xconst _XtString string, _Xconst _XtStrin
  *	Returns: none.
  */
 
-static String
+static char *
 StorePiecesInString(AsciiSrcObject src)
 {
-  String string;
+  char * string;
   XawTextPosition first;
   Piece * piece;
 

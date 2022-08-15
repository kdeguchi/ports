--- Scrollbar.h.orig	1996-10-15 14:41:21 UTC
+++ Scrollbar.h
@@ -116,10 +116,12 @@ SOFTWARE.
 #define XtCShown "Shown"
 #define XtCTopOfThumb "TopOfThumb"
 #define XtCPickTop "PickTop"
+#define XtCArrowScrollbars "ArrowScrollbars"
 
 #define XtNminimumThumb "minimumThumb"
 #define XtNtopOfThumb "topOfThumb"
 #define XtNpickTop "pickTop"
+#define XtNarrowScrollbars "arrowScrollbars"
 
 typedef struct _ScrollbarRec	  *ScrollbarWidget;
 typedef struct _ScrollbarClassRec *ScrollbarWidgetClass;

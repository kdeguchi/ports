--- ScrollbarP.h.orig	2003-02-10 17:22:26 UTC
+++ ScrollbarP.h
@@ -70,14 +70,12 @@ typedef struct {
     XtCallbackList thumbProc;	/* jump (to position) scroll */
     XtCallbackList jumpProc;	/* same as thumbProc but pass data by ref */
     Pixmap	  thumb;	/* thumb color */
-#ifndef XAW_ARROW_SCROLLBARS
     Cursor        upCursor;	/* scroll up cursor */
     Cursor        downCursor;	/* scroll down cursor */
     Cursor        leftCursor;	/* scroll left cursor */
     Cursor        rightCursor;	/* scroll right cursor */
     Cursor        verCursor;	/* scroll vertical cursor */
     Cursor        horCursor;	/* scroll horizontal cursor */
-#endif
     float	  top;		/* What percent is above the win's top */
     float	  shown;	/* What percent is shown in the win */
     Dimension	  length;	/* either height or width */
@@ -87,18 +85,16 @@ typedef struct {
 				 * when scrolling starts */
 
      /* private */
-#ifdef XAW_ARROW_SCROLLBARS
-    XtIntervalId  timer_id;     /* autorepeat timer; remove on destruction */
-    char	  scroll_mode;	/* 0:none 1:up/back 2:track 3:down/forward */
-#else
     Cursor        inactiveCursor; /* the normal cursor for scrollbar */
-    char          direction;	/* a scroll has started; which direction */
-#endif
+    char          direction;	/* 0:none, C:drag, F:down/forw, B:up/back */
     GC		  gc;		/* a (shared) gc */
     Position	  topLoc;	/* Pixel that corresponds to top */
     Dimension	  shownLength;	/* Num pixels corresponding to shown */
     Boolean       pick_top;     /* pick thumb at top or anywhere*/
+    Boolean       arrows;	/* Whether it has arrows at the end. */
 
+    /* Only used for arrow-scrollbars. */
+    XtIntervalId  timer_id;     /* autorepeat timer; remove on destruction */
 } ScrollbarPart;
 
 typedef struct _ScrollbarRec {

--- Scrollbar.c.orig	2003-02-10 17:22:26 UTC
+++ Scrollbar.c
@@ -53,6 +53,11 @@ SOFTWARE.
 
 ******************************************************************/
 
+/* TODO:
+   - avoid adhoc tests for `->arrows'.
+   - add support for scroll wheels.
+ */
+
 /* ScrollBar.c */
 /* created by weissman, Mon Jul  7 13:20:03 1986 */
 /* converted by swick, Thu Aug 27 1987 */
@@ -69,38 +74,48 @@ SOFTWARE.
 
 /* Private definitions. */
 
-#ifdef XAW_ARROW_SCROLLBARS
 static char defaultTranslations[] =
-    "<Btn1Down>:   NotifyScroll()\n\
-     <Btn2Down>:   MoveThumb() NotifyThumb() \n\
-     <Btn3Down>:   NotifyScroll()\n\
-     <Btn1Motion>: HandleThumb() \n\
-     <Btn3Motion>: HandleThumb() \n\
-     <Btn2Motion>: MoveThumb() NotifyThumb() \n\
-     <BtnUp>:      EndScroll()";
-#else
-static char defaultTranslations[] =
+#ifdef XAW_SCROLL_WHEEL
+    "<Btn4Down>:   StartScroll(Wheel, Backward) \n\
+     <Btn5Down>:   StartScroll(Wheel, Forward) \n"
+#endif
     "<Btn1Down>:   StartScroll(Forward) \n\
      <Btn2Down>:   StartScroll(Continuous) MoveThumb() NotifyThumb() \n\
      <Btn3Down>:   StartScroll(Backward) \n\
+     <Btn1Motion>: HandleThumb() \n\
+     <Btn3Motion>: HandleThumb() \n\
      <Btn2Motion>: MoveThumb() NotifyThumb() \n\
      <BtnUp>:      NotifyScroll(Proportional) EndScroll()";
-#ifdef bogusScrollKeys
-    /* examples */
-    "<KeyPress>f:  StartScroll(Forward) NotifyScroll(FullLength) EndScroll()"
-    "<KeyPress>b:  StartScroll(Backward) NotifyScroll(FullLength) EndScroll()"
-#endif
-#endif
+/* #ifdef XAW_ARROW_SCROLLBARS
+ *     "<Btn1Down>:   NotifyScroll()\n\
+ *      <Btn2Down>:   MoveThumb() NotifyThumb() \n\
+ *      <Btn3Down>:   NotifyScroll()\n\
+ *      <Btn1Motion>: HandleThumb() \n\
+ *      <Btn3Motion>: HandleThumb() \n\
+ *      <Btn2Motion>: MoveThumb() NotifyThumb() \n\
+ *      <BtnUp>:      EndScroll()";
+ * #else
+ *     "<Btn1Down>:   StartScroll(Forward) \n\
+ *      <Btn2Down>:   StartScroll(Continuous) MoveThumb() NotifyThumb() \n\
+ *      <Btn3Down>:   StartScroll(Backward) \n\
+ *      <Btn2Motion>: MoveThumb() NotifyThumb() \n\
+ *      <BtnUp>:      NotifyScroll(Proportional) EndScroll()";
+ * #ifdef bogusScrollKeys
+ *     /\* examples *\/
+ *     "<KeyPress>f:  StartScroll(Forward) NotifyScroll(FullLength) EndScroll()"
+ *     "<KeyPress>b:  StartScroll(Backward) NotifyScroll(FullLength) EndScroll()"
+ * #endif
+ * #endif */
 
 static float floatZero = 0.0;
 
 #define Offset(field) XtOffsetOf(ScrollbarRec, field)
 
 static XtResource resources[] = {
-#ifdef XAW_ARROW_SCROLLBARS
 /*  {XtNscrollCursor, XtCCursor, XtRCursor, sizeof(Cursor),
        Offset(scrollbar.cursor), XtRString, "crosshair"},*/
-#else
+  {XtNarrowScrollbars, XtCArrowScrollbars, XtRBoolean, sizeof(Boolean),
+       Offset(scrollbar.arrows), XtRBoolean, (XtPointer) False},
   {XtNscrollVCursor, XtCCursor, XtRCursor, sizeof(Cursor),
        Offset(scrollbar.verCursor), XtRString, "sb_v_double_arrow"},
   {XtNscrollHCursor, XtCCursor, XtRCursor, sizeof(Cursor),
@@ -113,7 +128,6 @@ static XtResource resources[] = {
        Offset(scrollbar.leftCursor), XtRString, "sb_left_arrow"},
   {XtNscrollRCursor, XtCCursor, XtRCursor, sizeof(Cursor),
        Offset(scrollbar.rightCursor), XtRString, "sb_right_arrow"},
-#endif
   {XtNlength, XtCLength, XtRDimension, sizeof(Dimension),
        Offset(scrollbar.length), XtRImmediate, (XtPointer) 1},
   {XtNthickness, XtCThickness, XtRDimension, sizeof(Dimension),
@@ -149,22 +163,16 @@ static void Resize();
 static void Redisplay();
 static Boolean SetValues();
 
-#ifdef XAW_ARROW_SCROLLBARS
 static void HandleThumb();
-#else
 static void StartScroll();
-#endif
 static void MoveThumb();
 static void NotifyThumb();
 static void NotifyScroll();
 static void EndScroll();
 
 static XtActionsRec actions[] = {
-#ifdef XAW_ARROW_SCROLLBARS
     {"HandleThumb",	HandleThumb},
-#else
     {"StartScroll",     StartScroll},
-#endif
     {"MoveThumb",	MoveThumb},
     {"NotifyThumb",	NotifyThumb},
     {"NotifyScroll",	NotifyScroll},
@@ -235,12 +243,11 @@ static void ClassInitialize()
 		    (XtConvertArgList)NULL, (Cardinal)0 );
 }
 
-#ifdef XAW_ARROW_SCROLLBARS
-/* CHECKIT #define MARGIN(sbw) (sbw)->scrollbar.thickness + (sbw)->threeD.shadow_width */
-#define MARGIN(sbw) (sbw)->scrollbar.thickness
-#else
-#define MARGIN(sbw) (sbw)->threeD.shadow_width
-#endif
+#define MARGIN(sbw)							\
+    ((sbw)->scrollbar.arrows						\
+     /* CHECKIT (sbw)->scrollbar.thickness + (sbw)->threeD.shadow_width */ \
+     ? (sbw)->scrollbar.thickness					\
+     : (sbw)->threeD.shadow_width)
 
 /* 
  The original Xaw Scrollbar's FillArea *really* relied on the fact that the 
@@ -357,7 +364,6 @@ static void PaintThumb (sbw, event)
     }
 }
 
-#ifdef XAW_ARROW_SCROLLBARS
 static void PaintArrows (sbw)
     ScrollbarWidget sbw;
 {
@@ -453,7 +459,6 @@ static void PaintArrows (sbw)
 	}
     }
 }
-#endif
 
 /*	Function Name: Destroy
  *	Description: Called as the scrollbar is going away...
@@ -464,10 +469,8 @@ static void Destroy (w)
     Widget w;
 {
     ScrollbarWidget sbw = (ScrollbarWidget) w;
-#ifdef XAW_ARROW_SCROLLBARS
     if(sbw->scrollbar.timer_id != (XtIntervalId) 0)
 	XtRemoveTimeOut (sbw->scrollbar.timer_id);
-#endif
     XtReleaseGC (w, sbw->scrollbar.gc);
 }
 
@@ -552,12 +555,8 @@ static void Initialize( request, new, args, num_args )
 	    ? sbw->scrollbar.thickness : sbw->scrollbar.length;
 
     SetDimensions (sbw);
-#ifdef XAW_ARROW_SCROLLBARS
-    sbw->scrollbar.scroll_mode = 0;
     sbw->scrollbar.timer_id = (XtIntervalId)0;
-#else
     sbw->scrollbar.direction = 0;
-#endif
     sbw->scrollbar.topLoc = 0;
     sbw->scrollbar.shownLength = sbw->scrollbar.min_thumb;
 }
@@ -568,19 +567,19 @@ static void Realize (w, valueMask, attributes)
     XSetWindowAttributes *attributes;
 {
     ScrollbarWidget sbw = (ScrollbarWidget) w;
-#ifdef XAW_ARROW_SCROLLBARS
-    if(sbw->simple.cursor_name == NULL)
-	XtVaSetValues(w, XtNcursorName, "crosshair", NULL);
-    /* dont set the cursor of the window to anything */
-    *valueMask &= ~CWCursor;
-#else
-    sbw->scrollbar.inactiveCursor =
-      (sbw->scrollbar.orientation == XtorientVertical)
-	? sbw->scrollbar.verCursor
-	: sbw->scrollbar.horCursor;
+    if (sbw->scrollbar.arrows) {
+	/* if (sbw->simple.cursor_name == NULL)
+	 *     XtVaSetValues(w, XtNcursorName, "crosshair", NULL); */
+	/* dont set the cursor of the window to anything */
+	*valueMask &= ~CWCursor;
+    } else {
+	sbw->scrollbar.inactiveCursor =
+	    (sbw->scrollbar.orientation == XtorientVertical)
+	    ? sbw->scrollbar.verCursor
+	    : sbw->scrollbar.horCursor;
 
-    XtVaSetValues (w, XtNcursor, sbw->scrollbar.inactiveCursor, NULL);
-#endif
+	XtVaSetValues (w, XtNcursor, sbw->scrollbar.inactiveCursor, NULL);
+    }
     /* 
      * The Simple widget actually stuffs the value in the valuemask. 
      */
@@ -669,11 +668,9 @@ static void Redisplay (w, event, region)
 	sbw->scrollbar.topLoc = -(sbw->scrollbar.length + 1);
 	PaintThumb (sbw, event); 
     }
-#ifdef XAW_ARROW_SCROLLBARS
-    /* we'd like to be region aware here!!!! */
-    PaintArrows (sbw);
-#endif
-
+    if (sbw->scrollbar.arrows)
+	/* we'd like to be region aware here!!!! */
+	PaintArrows (sbw);
 }
 
 
@@ -776,7 +773,6 @@ static void ExtractPosition (event, x, y)
     }
 }
 
-#ifdef XAW_ARROW_SCROLLBARS
 /* ARGSUSED */
 static void HandleThumb (w, event, params, num_params)
     Widget w;
@@ -787,10 +783,14 @@ static void HandleThumb (w, event, params, num_params)
     Position x,y;
     ScrollbarWidget sbw = (ScrollbarWidget) w;
 
+    /* The old non-ARROW_SCROLLBAR binding emulation:
+       HandleThumb() -> <nothing>  */
+    if (!sbw->scrollbar.arrows) return;
+
     ExtractPosition( event, &x, &y );
     /* if the motion event puts the pointer in thumb, call Move and Notify */
     /* also call Move and Notify if we're already in continuous scroll mode */
-    if (sbw->scrollbar.scroll_mode == 2 ||
+    if (sbw->scrollbar.direction == 'C' ||
 	(PICKLENGTH (sbw,x,y) >= sbw->scrollbar.topLoc &&
 	PICKLENGTH (sbw,x,y) <= sbw->scrollbar.topLoc + sbw->scrollbar.shownLength)){
 	XtCallActionProc(w, "MoveThumb", event, params, *num_params);
@@ -805,12 +805,12 @@ static void RepeatNotify (client_data, idp)
 #define A_FEW_PIXELS 5
     ScrollbarWidget sbw = (ScrollbarWidget) client_data;
     int call_data;
-    if (sbw->scrollbar.scroll_mode != 1 && sbw->scrollbar.scroll_mode != 3) {
+    if (sbw->scrollbar.direction != 'B' && sbw->scrollbar.direction != 'F') {
 	sbw->scrollbar.timer_id = (XtIntervalId) 0;
 	return;
     }
     call_data = MAX (A_FEW_PIXELS, sbw->scrollbar.length / 20);
-    if (sbw->scrollbar.scroll_mode == 1)
+    if (sbw->scrollbar.direction == 'B')
 	call_data = -call_data;
     XtCallCallbacks((Widget)sbw, XtNscrollProc, (XtPointer) call_data);
     sbw->scrollbar.timer_id = 
@@ -820,12 +820,11 @@ static void RepeatNotify (client_data, idp)
 		    client_data);
 }
 
-#else /* XAW_ARROW_SCROLLBARS */
 /* ARGSUSED */
 static void StartScroll (w, event, params, num_params )
     Widget w;
     XEvent *event;
-    String *params;		/* direction: Back|Forward|Smooth */
+    String *params;		/* direction: Back|Forward|Continuous */
     Cardinal *num_params;	/* we only support 1 */
 {
     ScrollbarWidget sbw = (ScrollbarWidget) w;
@@ -833,11 +832,24 @@ static void StartScroll (w, event, params, num_params 
     char direction;
 
     if (sbw->scrollbar.direction != 0) return; /* if we're already scrolling */
-    if (*num_params > 0) 
+    if (*num_params > 0)
 	direction = *params[0];
     else
 	direction = 'C';
 
+    if (sbw->scrollbar.arrows) {
+	/* The old ARROW_SCROLLBAR binding emulation:
+	 StartScroll(Forward) -> NotifyScroll()
+	 StartScroll(Backward) -> NotifyScroll()
+	 StartScroll(Continuous) -> <nothing>  */
+	switch (direction) {
+	case 'b': case 'B': case 'f': case 'F':
+	    NotifyScroll(w, event, params, 0);
+	    break;
+	}
+	return;
+    }
+
     sbw->scrollbar.direction = direction;
 
     switch (direction) {
@@ -865,20 +877,17 @@ static void StartScroll (w, event, params, num_params 
     XtVaSetValues (w, XtNcursor, cursor, NULL);
     XFlush (XtDisplay (w));
 }
-#endif /* XAW_ARROW_SCROLLBARS */
 
 /*
  * Make sure the first number is within the range specified by the other
  * two numbers.
  */
 
-#ifndef XAW_ARROW_SCROLLBARS
 static int InRange(num, small, big)
     int num, small, big;
 {
     return (num < small) ? small : ((num > big) ? big : num);
 }
-#endif
 
 /*
  * Same as above, but for floating numbers. 
@@ -891,7 +900,6 @@ static float FloatInRange(num, small, big)
 }
 
 
-#ifdef XAW_ARROW_SCROLLBARS
 static void NotifyScroll (w, event, params, num_params)
     Widget w;
     XEvent *event;
@@ -902,94 +910,94 @@ static void NotifyScroll (w, event, params, num_params
     int call_data;
     Position x, y;
 
-    if (sbw->scrollbar.scroll_mode == 2  /* if scroll continuous */
-	|| LookAhead (w, event)) 
-	return;
+    if (sbw->scrollbar.arrows) {
+	if (sbw->scrollbar.direction == 'C' /* if scroll continuous */
+	    || LookAhead (w, event)) 
+	    return;
 
-    ExtractPosition (event, &x, &y);
+	/* Old ARROW_SCROLLBAR bindings emulation:
+	   NotifyScroll(Proportional) -> <nothing>  */
+	if (num_params > 0 && (*params[0] == 'P' || *params[0] == 'p'))
+	    return;
 
-    if (PICKLENGTH (sbw,x,y) < sbw->scrollbar.thickness) {
-	/* handle first arrow zone */
-	call_data = -MAX (A_FEW_PIXELS, sbw->scrollbar.length / 20);
-	XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
-	/* establish autoscroll */
-	sbw->scrollbar.timer_id = 
-	    XtAppAddTimeOut (XtWidgetToApplicationContext (w),
-				(unsigned long) 300, RepeatNotify, (XtPointer)w);
-	sbw->scrollbar.scroll_mode = 1;
-    } else if (PICKLENGTH (sbw,x,y) > sbw->scrollbar.length - sbw->scrollbar.thickness) {
-	/* handle last arrow zone */
-	call_data = MAX (A_FEW_PIXELS, sbw->scrollbar.length / 20);
-	XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
-	/* establish autoscroll */
-	sbw->scrollbar.timer_id =
-	    XtAppAddTimeOut (XtWidgetToApplicationContext (w), 
-				(unsigned long) 300, RepeatNotify, (XtPointer)w);
-	sbw->scrollbar.scroll_mode = 3;
-    } else if (PICKLENGTH (sbw, x, y) < sbw->scrollbar.topLoc) {
-	/* handle zone "above" the thumb */
-	call_data = - sbw->scrollbar.length;
-	XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
-    } else if (PICKLENGTH (sbw, x, y) > sbw->scrollbar.topLoc + sbw->scrollbar.shownLength) {
-	/* handle zone "below" the thumb */
-	call_data = sbw->scrollbar.length;
-	XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
-    } else 
-	{
-	/* handle the thumb in the motion notify action */
-	}
-    return;
-}
-#else /* XAW_ARROW_SCROLLBARS */
-static void NotifyScroll (w, event, params, num_params)
-    Widget w;
-    XEvent *event;
-    String *params;		/* style: Proportional|FullLength */
-    Cardinal *num_params;	/* we only support 1 */
-{
-    ScrollbarWidget sbw = (ScrollbarWidget) w;
-    int call_data;
-    char style;
-    Position x, y;
+	ExtractPosition (event, &x, &y);
 
-    if (sbw->scrollbar.direction == 0) return; /* if no StartScroll */
-    if (LookAhead (w, event)) return;
-    if (*num_params > 0) 
-	style = *params[0];
-    else
-	style = 'P';
+	if (PICKLENGTH (sbw,x,y) < sbw->scrollbar.thickness) {
+	    /* handle first arrow zone */
+	    call_data = -MAX (A_FEW_PIXELS, sbw->scrollbar.length / 20);
+	    XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
+	    /* establish autoscroll */
+	    sbw->scrollbar.timer_id = 
+		XtAppAddTimeOut (XtWidgetToApplicationContext (w),
+				 (unsigned long) 300, RepeatNotify, (XtPointer)w);
+	    sbw->scrollbar.direction = 'B';
+	} else if (PICKLENGTH (sbw,x,y) > sbw->scrollbar.length - sbw->scrollbar.thickness) {
+	    /* handle last arrow zone */
+	    call_data = MAX (A_FEW_PIXELS, sbw->scrollbar.length / 20);
+	    XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
+	    /* establish autoscroll */
+	    sbw->scrollbar.timer_id =
+		XtAppAddTimeOut (XtWidgetToApplicationContext (w), 
+				 (unsigned long) 300, RepeatNotify, (XtPointer)w);
+	    sbw->scrollbar.direction = 'F';
+	} else if (PICKLENGTH (sbw, x, y) < sbw->scrollbar.topLoc) {
+	    /* handle zone "above" the thumb */
+	    call_data = - sbw->scrollbar.length;
+	    XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
+	} else if (PICKLENGTH (sbw, x, y) > sbw->scrollbar.topLoc + sbw->scrollbar.shownLength) {
+	    /* handle zone "below" the thumb */
+	    call_data = sbw->scrollbar.length;
+	    XtCallCallbacks (w, XtNscrollProc, (XtPointer)(call_data));
+	} else 
+	    {
+		/* handle the thumb in the motion notify action */
+	    }
+    } else { /* XAW_ARROW_SCROLLBARS */
+	char style;
 
-    switch (style) {
-    case 'P':    /* Proportional */
-    case 'p':
-	ExtractPosition (event, &x, &y);
-	call_data = 
-	    InRange (PICKLENGTH (sbw, x, y), 0, (int) sbw->scrollbar.length); 
-	break;
+	if (sbw->scrollbar.direction == 0)
+	    /* Either we haven't yet done StartScoll, or w've already done
+	       an EndScroll (e.g: Btn1Down, Btn2Down, Btn2up, Btn1up). */
+	    return;
+	if (LookAhead (w, event)) return;
+	if (*num_params > 0) 
+	    style = *params[0];
+	else
+	    style = 'P';
 
-    case 'F':    /* FullLength */
-    case 'f':    
-	call_data = sbw->scrollbar.length; 
-	break;
-    }
-    switch (sbw->scrollbar.direction) {
-    case 'B':
-    case 'b':    
-	call_data = -call_data;
-	/* fall through */
+	switch (style) {
+	case 'P':    /* Proportional */
+	case 'p':
+	    ExtractPosition (event, &x, &y);
+	    call_data = 
+		InRange (PICKLENGTH (sbw, x, y), 0, (int) sbw->scrollbar.length); 
+	    break;
 
-    case 'F':
-    case 'f':    
-	XtCallCallbacks (w, XtNscrollProc, (XtPointer)call_data);
-	break;
+	/* case 'F':    /\* FullLength *\/
+	 * case 'f':     */
+	default:
+	    call_data = sbw->scrollbar.length; 
+	    break;
+	}
 
-    case 'C':
-    case 'c':
-	/* NotifyThumb has already called the thumbProc(s) */
-	break;
-    }
+	switch (sbw->scrollbar.direction) {
+	case 'B':
+	case 'b':    
+	    call_data = -call_data;
+	    /* fall through */
+
+	case 'F':
+	case 'f':    
+	    XtCallCallbacks (w, XtNscrollProc, (XtPointer)call_data);
+	    break;
+
+	case 'C':
+	case 'c':
+	    /* NotifyThumb has already called the thumbProc(s) */
+	    break;
+	}
+    } /* XAW_ARROW_SCROLLBARS */
 }
-#endif /* XAW_ARROW_SCROLLBARS */
 
 /* ARGSUSED */
 static void EndScroll(w, event, params, num_params )
@@ -1000,23 +1008,18 @@ static void EndScroll(w, event, params, num_params )
 {
     ScrollbarWidget sbw = (ScrollbarWidget) w;
 
-#ifdef XAW_ARROW_SCROLLBARS
-    sbw->scrollbar.scroll_mode = 0;
-    /* no need to remove any autoscroll timeout; it will no-op */
-    /* because the scroll_mode is 0 */
-    /* but be sure to remove timeout in destroy proc */
-#else
     XtVaSetValues (w, XtNcursor, sbw->scrollbar.inactiveCursor, NULL);
     XFlush (XtDisplay (w));
     sbw->scrollbar.direction = 0;
-#endif
+    /* no need to remove any autoscroll timeout; it will no-op */
+    /* because the direction is 0 */
+    /* but be sure to remove timeout in destroy proc */
 }
 
 static float FractionLoc (sbw, x, y)
     ScrollbarWidget sbw;
     int x, y;
 {
-    float   result;
     int margin;
     float   height, width;
 
@@ -1025,8 +1028,7 @@ static float FractionLoc (sbw, x, y)
     y -= margin;
     height = sbw->core.height - 2 * margin;
     width = sbw->core.width - 2 * margin;
-    result = PICKLENGTH (sbw, x / width, y / height);
-    return FloatInRange(result, 0.0, 1.0);
+    return PICKLENGTH (sbw, x / width, y / height);
 }
 
 
@@ -1038,42 +1040,34 @@ static void MoveThumb (w, event, params, num_params)
 {
     ScrollbarWidget sbw = (ScrollbarWidget) w;
     Position x, y;
-    float loc, t, s;
+    float loc;
 
-#ifndef XAW_ARROW_SCROLLBARS
-    if (sbw->scrollbar.direction == 0) return; /* if no StartScroll */
-#endif
+    if (!sbw->scrollbar.arrows)
+	if (sbw->scrollbar.direction == 0) return; /* if no StartScroll */
 
     if (LookAhead (w, event)) return;
 
     if (!event->xmotion.same_screen) return;
 
     ExtractPosition (event, &x, &y);
-    loc = FractionLoc (sbw, x, y);
-    t = sbw->scrollbar.top;
-    s = sbw->scrollbar.shown;
-#ifdef XAW_ARROW_SCROLLBARS
-    if (sbw->scrollbar.scroll_mode != 2 )
-      /* initialize picked position */
-      sbw->scrollbar.picked = (FloatInRange( loc, t, t + s ) - t);
-#else
-    sbw->scrollbar.picked = 0.5 * s;
-#endif
-    if (sbw->scrollbar.pick_top)
-      sbw->scrollbar.top = loc;
-    else {
-      sbw->scrollbar.top = loc - sbw->scrollbar.picked;
-      if (sbw->scrollbar.top < 0.0) sbw->scrollbar.top = 0.0;
+
+    if (sbw->scrollbar.direction != 'C') {
+	/* initialize picked position offset */
+	sbw->scrollbar.picked
+	    = sbw->scrollbar.pick_top ? 0
+	    : FractionLoc (sbw, x, y) - sbw->scrollbar.top;
     }
 
+    loc = FractionLoc (sbw, x, y) - sbw->scrollbar.picked;
+    
+    sbw->scrollbar.top = FloatInRange (loc, 0.0, 1.0);
+
 #if 0
     /* this breaks many text-line scrolls */
     if (sbw->scrollbar.top + sbw->scrollbar.shown > 1.0)
       sbw->scrollbar.top = 1.0 - sbw->scrollbar.shown;
 #endif
-#ifdef XAW_ARROW_SCROLLBARS
-    sbw->scrollbar.scroll_mode = 2; /* indicate continuous scroll */
-#endif
+    sbw->scrollbar.direction = 'C'; /* indicate continuous scroll */
     PaintThumb (sbw, event);
     XFlush (XtDisplay (w));	/* re-draw it before Notifying */
 }
@@ -1089,9 +1083,8 @@ static void NotifyThumb (w, event, params, num_params 
     register ScrollbarWidget sbw = (ScrollbarWidget) w;
     float top = sbw->scrollbar.top;
 
-#ifndef XAW_ARROW_SCROLLBARS
-    if (sbw->scrollbar.direction == 0) return; /* if no StartScroll */
-#endif
+    if (!sbw->scrollbar.arrows)
+	if (sbw->scrollbar.direction == 0) return; /* if no StartScroll */
 
     if (LookAhead (w, event)) return;
 
@@ -1150,12 +1143,6 @@ void XawScrollbarSetThumb (w, top, shown)
 #ifdef WIERD
     fprintf(stderr,"< XawScrollbarSetThumb w=%p, top=%f, shown=%f\n", 
 	    w,top,shown);
-#endif
-
-#ifdef XAW_ARROW_SCROLLBARS
-    if (sbw->scrollbar.scroll_mode == (char) 2) return; /* if still thumbing */
-#else
-    if (sbw->scrollbar.direction == 'c') return; /* if still thumbing */
 #endif
 
     sbw->scrollbar.top = (top > 1.0) ? 1.0 :

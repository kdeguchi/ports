--- src/TextAction.c.orig	2018-06-19 05:00:59 UTC
+++ src/TextAction.c
@@ -1218,7 +1218,7 @@ ExtendEnd(Widget w, XEvent *event, String *params, Car
 static void
 SelectSave(Widget w, XEvent *event, String *params, Cardinal *num_params)
 {
-    int	    num_atoms;
+    int	    num_atoms, n;
     Atom*   sel;
     Display* dpy = XtDisplay(w);
     Atom    selections[256];
@@ -1227,9 +1227,8 @@ SelectSave(Widget w, XEvent *event, String *params, Ca
     num_atoms = *num_params;
     if (num_atoms > 256)
 	num_atoms = 256;
-    for (sel=selections; --num_atoms >= 0; sel++, params++)
+    for (sel = selections, n = 0; n < num_atoms; n++, sel++, params++)
 	*sel = XInternAtom(dpy, *params, False);
-    num_atoms = *num_params;
     _XawTextSaltAwaySelection( (TextWidget) w, selections, num_atoms );
     EndAction(  (TextWidget) w );
 }

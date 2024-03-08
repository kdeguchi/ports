--- src/TMparse.c.orig	2023-04-09 20:48:48 UTC
+++ src/TMparse.c
@@ -99,6 +99,15 @@ in this Software without prior written authorization f
 #define MIN(a,b) (((a) < (b)) ? (a) : (b))
 #endif
 
+/* The core X11R6 protocol predates 7-button mice.
+ * This prevents us from referring to those buttons in event masks.
+ * We *can* recognize basic up/down events for those buttons, since
+ * those use the plain button number.  Compare with the "Button5"
+ * pre-processor definition in "X.h".
+ */
+#define XtButton6		6
+#define XtButton7		7
+
 static _Xconst char *XtNtranslationParseError = "translationParseError";
 
 typedef int EventType;
@@ -162,6 +171,8 @@ static ModifierRec modifiers[] = {
     {"Button3", 0,      ParseModImmed, Button3Mask},
     {"Button4", 0,      ParseModImmed, Button4Mask},
     {"Button5", 0,      ParseModImmed, Button5Mask},
+    {"Button6", 0,      ParseModImmed, XtButton6},
+    {"Button7", 0,      ParseModImmed, XtButton7},
     {"c",       0,      ParseModImmed, ControlMask},
     {"s",       0,      ParseModImmed, ShiftMask},
     {"l",       0,      ParseModImmed, LockMask},
@@ -252,6 +263,8 @@ static EventKey events[] = {
 {"Btn3Down",        NULLQUARK, ButtonPress,     ParseImmed, (Opaque)Button3},
 {"Btn4Down",        NULLQUARK, ButtonPress,     ParseImmed, (Opaque)Button4},
 {"Btn5Down",        NULLQUARK, ButtonPress,     ParseImmed, (Opaque)Button5},
+{"Btn6Down",        NULLQUARK, ButtonPress,     ParseImmed,(Opaque)XtButton6},
+{"Btn7Down",        NULLQUARK, ButtonPress,     ParseImmed,(Opaque)XtButton7},
 
 /* Event Name,    Quark, Event Type,    Detail Parser, Closure */
 
@@ -262,6 +275,8 @@ static EventKey events[] = {
 {"Btn3Up",          NULLQUARK, ButtonRelease,   ParseImmed, (Opaque)Button3},
 {"Btn4Up",          NULLQUARK, ButtonRelease,   ParseImmed, (Opaque)Button4},
 {"Btn5Up",          NULLQUARK, ButtonRelease,   ParseImmed, (Opaque)Button5},
+{"Btn6Up",          NULLQUARK, ButtonRelease,   ParseImmed,(Opaque)XtButton6},
+{"Btn7Up",          NULLQUARK, ButtonRelease,   ParseImmed,(Opaque)XtButton7},
 
 {"MotionNotify",    NULLQUARK, MotionNotify,    ParseTable, (Opaque)motionDetails},
 {"PtrMoved",        NULLQUARK, MotionNotify,    ParseTable, (Opaque)motionDetails},

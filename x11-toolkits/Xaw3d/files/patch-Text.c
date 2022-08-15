--- Text.c.orig	2003-02-10 17:28:13 UTC
+++ Text.c
@@ -1462,10 +1462,8 @@ XtPointer callData;		/* #pixels */
   if (height < 1)
     height = 1;
   nlines = (int) (lines * (int) ctx->text.lt.lines) / height;
-#ifdef XAW_ARROW_SCROLLBARS
   if (nlines == 0 && lines != 0) 
     nlines = lines > 0 ? 1 : -1;
-#endif
   _XawTextPrepareToUpdate(ctx);
   _XawTextVScroll(ctx, nlines);
   _XawTextExecuteUpdate(ctx);

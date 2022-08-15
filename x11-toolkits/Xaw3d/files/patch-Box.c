--- Box.c.orig	1996-10-15 14:41:18 UTC
+++ Box.c
@@ -353,8 +353,11 @@ static XtGeometryResult PreferredSize(widget, constrai
 	else {
 	    width = preferred_width;
 	    do { /* find some width big enough to stay within this height */
-		width *= 2;
-		if (width > constraint->width) width = constraint->width;
+		if (width > constraint->width/2) /* avoid short int overflow */
+		    width = constraint->width;
+		else
+		    width *= 2;
+
 		DoLayout(w, width, 0, &preferred_width, &preferred_height, FALSE);
 	    } while (preferred_height > constraint->height &&
 		     width < constraint->width);

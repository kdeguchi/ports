--- calendar.c.orig	2023-01-13 08:21:06 UTC
+++ calendar.c
@@ -877,7 +877,7 @@ void errprint(const char *func, int level, const char 
 
 	va_start(ap, fmt);
 
-	fprintf(stderr, "calendar: ");
+	fprintf(stderr, "calendar: %s");
 	if (level != ERR_INFO) {
 		fprintf(stderr, "%s: ", statname[level - ERR_WARN]);
 	}

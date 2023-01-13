--- main.c.orig	2023-01-13 08:21:06 UTC
+++ main.c
@@ -228,7 +228,7 @@ void errprint(const char *func, int level, const char 
 
 	va_start(ap, fmt);
 
-	fprintf(stderr, "today: ");
+	fprintf(stderr, "today: %s");
 	if (level != ERR_INFO) {
 		fprintf(stderr, "%s: ", statname[level - ERR_WARN]);
 	}

--- autoenc.c.orig	2020-04-23 01:08:31 UTC
+++ autoenc.c
@@ -554,9 +554,9 @@ static void send_with_encryption(gpointer compose)
 			       filename, NULL);
 	cmdline = g_string_new("");
 	if (arc_path) {
-		g_string_append_printf(cmdline, "\"%s\\7z\" a -y ", arc_path);
+		g_string_append_printf(cmdline, "\"%s\\7zz\" a -y ", arc_path);
 	} else {
-		g_string_append(cmdline, "7z a -y ");
+		g_string_append(cmdline, "7zz a -y ");
 	}
 	g_string_append(cmdline, "-p");
 	g_string_append(cmdline, password);

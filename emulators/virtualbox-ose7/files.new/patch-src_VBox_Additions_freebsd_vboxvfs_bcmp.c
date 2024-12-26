--- src/VBox/Additions/freebsd/vboxvfs/bcmp.c.orig	2024-12-26 02:54:47 UTC
+++ src/VBox/Additions/freebsd/vboxvfs/bcmp.c
@@ -0,0 +1,9 @@
+#include <sys/types.h>
+
+int bcmp(const void *b1, const void *b2, size_t len);
+
+int
+bcmp(const void *b1, const void *b2, size_t len)
+{
+	return __builtin_memcmp((b1), (b2), (len));
+}

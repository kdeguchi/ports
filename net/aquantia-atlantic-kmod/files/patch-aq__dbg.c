--- aq_dbg.c.orig	2022-01-25 07:53:28 UTC
+++ aq_dbg.c
@@ -41,7 +41,7 @@ __FBSDID("$FreeBSD$");
 __FBSDID("$FreeBSD$");
 
 #include <sys/param.h>
-#include "aq_common.h"
+#include "aq.h"
 #include "aq_dbg.h"
 
 
@@ -234,4 +234,4 @@ void DumpHex(const void* data, size_t size) {
 		}
 	}
 #endif
-}
\ No newline at end of file
+}

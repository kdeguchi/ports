--- src/command.c.orig	2019-11-19 21:57:18 UTC
+++ src/command.c
@@ -115,6 +115,7 @@ int thread_rl_RetCode = -1; /* return code from readli
 
 #ifndef _Windows
 # include "help.h"
+# include <sys/wait.h>
 #endif /* _Windows */
 
 #ifdef _Windows

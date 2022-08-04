--- src/base/init_mozc.cc.orig	2022-02-16 08:01:21 UTC
+++ src/base/init_mozc.cc
@@ -34,6 +34,7 @@
 #endif  // OS_WIN
 
 #include <string>
+#include <stdlib.h>
 
 
 #include "base/file_util.h"
@@ -110,7 +111,9 @@ void InitMozc(const char *arg0, int *argc, char ***arg
   ParseCommandLineFlags(*argc, *argv);
 
   const std::string program_name = *argc > 0 ? (*argv)[0] : "UNKNOWN";
-  Logging::InitLogStream(GetLogFilePathFromProgramName(program_name));
+  const char *nolog = getenv("MOZC_NOLOG");
+  if (nolog == NULL)
+    Logging::InitLogStream(GetLogFilePathFromProgramName(program_name));
 
 }
 

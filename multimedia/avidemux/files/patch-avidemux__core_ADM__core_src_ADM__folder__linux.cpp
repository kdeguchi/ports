--- avidemux_core/ADM_core/src/ADM_folder_linux.cpp.orig	2024-09-20 19:15:55 UTC
+++ avidemux_core/ADM_core/src/ADM_folder_linux.cpp
@@ -41,7 +41,7 @@ static std::string canonize(const std::string &in)
 static std::string canonize(const std::string &in)
 {
     std::string out;
-    char *simple2=canonicalize_file_name(in.c_str());
+    char *simple2=realpath(in.c_str(),nullptr);
     if(simple2)
     {
         out=std::string(simple2);

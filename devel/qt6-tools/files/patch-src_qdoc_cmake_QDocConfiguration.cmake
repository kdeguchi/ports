--- src/qdoc/cmake/QDocConfiguration.cmake.orig	2026-05-08 01:19:07 UTC
+++ src/qdoc/cmake/QDocConfiguration.cmake
@@ -8,8 +8,11 @@ set(QDOC_SUPPORTED_CLANG_VERSIONS
 
 # List of explicitly supported Clang versions for QDoc
 set(QDOC_SUPPORTED_CLANG_VERSIONS
-    "21.1" "20.1" "19.1" "18.1" "17.0.6"
+    "22.1" "22.0" "21.1" "20.1" "19.1" "18.1" "17.0.6"
 )
+
+# Try user-selected version of Clang first
+list(PREPEND QDOC_SUPPORTED_CLANG_VERSIONS "${QDOC_USER_CLANG_VERSION}")
 
 # Check for QDoc coverage dependencies
 find_program(LCOV_EXECUTABLE lcov DOC "Path to lcov executable")

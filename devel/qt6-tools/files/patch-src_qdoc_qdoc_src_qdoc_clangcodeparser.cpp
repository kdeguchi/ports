--- src/qdoc/qdoc/src/qdoc/clangcodeparser.cpp.orig	2026-05-08 01:19:07 UTC
+++ src/qdoc/qdoc/src/qdoc/clangcodeparser.cpp
@@ -42,7 +42,12 @@
 #include <clang/Lex/Lexer.h>
 #include <llvm/Support/Casting.h>
 
-#include "clang/AST/QualTypeNames.h"
+#if LIBCLANG_VERSION_MAJOR >= 22
+// LLVM 22 provides a compatible QualTypeNames implementation in libclang.
+#  include <clang/AST/QualTypeNames.h>
+#else
+#  include "clang/AST/QualTypeNames.h"
+#endif
 #include "template_declaration.h"
 
 #include <cstdio>

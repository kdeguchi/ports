--- src/qdoc/qdoc/src/qdoc/clangcodeparser.cpp.orig	2026-01-20 08:51:38 UTC
+++ src/qdoc/qdoc/src/qdoc/clangcodeparser.cpp
@@ -39,7 +39,12 @@
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

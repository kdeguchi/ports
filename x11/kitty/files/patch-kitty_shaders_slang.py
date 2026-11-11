--- kitty/shaders/slang.py.orig	2026-11-07 12:10:37 UTC
+++ kitty/shaders/slang.py
@@ -358,7 +358,7 @@ class LoadShaderPrograms:
                         # a bare "No such file or directory" gives no hint as to why.
                         err(
                             f'Failed to build custom shader for slot {slot} because the slang shader compiler'
-                            f' ({slangc()[0]}) was not found. Install shader-slang to use custom shaders.'
+                            f' ({slangc()[0]}) was not found. Install package graphics/linux-slang to use custom shaders.'
                         )
                     else:
                         err(f'Failed to build custom shader for slot {slot} with error: {e}')

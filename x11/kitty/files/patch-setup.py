--- setup.py.orig	2022-10-13 07:35:40 UTC
+++ setup.py
@@ -528,6 +528,7 @@ def get_source_specific_defines(env: Env, src: str) ->
     if src == 'kitty/parser_dump.c':
         return 'kitty/parser.c', ['DUMP_COMMANDS']
     if src == 'kitty/data-types.c':
+        env.ldflags.append('-lulog')
         return src, get_vcs_rev_defines(env, src)
     with suppress(KeyError):
         return src, env.library_paths[src]

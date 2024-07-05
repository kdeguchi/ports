--- setup.py.orig	2024-05-08 04:55:54 UTC
+++ setup.py
@@ -720,6 +700,7 @@ def get_source_specific_defines(env: Env, src: str) ->
     if src == 'kitty/data-types.c':
         if not env.vcs_rev:
             env.vcs_rev = get_vcs_rev()
+            env.ldflags.append('-lutempter')
         return src, [], [f'KITTY_VCS_REV="{env.vcs_rev}"', f'WRAPPED_KITTENS="{wrapped_kittens()}"']
     if src.startswith('3rdparty/base64/'):
         return src, ['3rdparty/base64',], base64_defines(env.binary_arch.isa)
@@ -1333,8 +1333,8 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
     base = Path(ddir)
     in_src_launcher = base / (f'{libdir_name}/kitty/kitty/launcher/kitty')
     launcher = base / 'bin/kitty'
-    skip_docs = False
-    if not os.path.exists('docs/_build/html'):
+    skip_docs = os.getenv('BUILD_DOCS') != 'yes'
+    if not os.path.exists('docs/_build/html') and not skip_docs:
         kitten_exe = os.path.join(os.path.dirname(str(launcher)), 'kitten')
         if os.path.exists(kitten_exe):
             os.environ['KITTEN_EXE_FOR_DOCS'] = kitten_exe

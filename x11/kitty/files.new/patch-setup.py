--- setup.py.orig	2024-05-08 04:55:54 UTC
+++ setup.py
@@ -253,31 +253,11 @@ def libcrypto_flags() -> Tuple[List[str], List[str]]:
     # Apple use their special snowflake TLS libraries and additionally
     # have an ancient broken system OpenSSL, so we need to check for one
     # installed by all the various macOS package managers.
-    extra_pc_dir = ''
+    cflags = [f"-I{sys.prefix}/include"]
+    libs = [f"-L{sys.prefix}/lib", "-lcrypto"]
+    return cflags, libs
 
-    try:
-        cflags = pkg_config('libcrypto', '--cflags-only-I', fatal=False)
-    except subprocess.CalledProcessError:
-        if is_macos:
-            import ssl
-            v = ssl.OPENSSL_VERSION_INFO
-            pats = f'{v[0]}.{v[1]}', f'{v[0]}'
-            for pat in pats:
-                q = f'opt/openssl@{pat}/lib/pkgconfig'
-                openssl_dirs = glob.glob(f'/opt/homebrew/{q}') + glob.glob(f'/usr/local/{q}')
-                if openssl_dirs:
-                    break
-            else:
-                raise SystemExit(f'Failed to find OpenSSL version {v[0]}.{v[1]} on your system')
-            extra_pc_dir = os.pathsep.join(openssl_dirs)
-        cflags = pkg_config('libcrypto', '--cflags-only-I', extra_pc_dir=extra_pc_dir)
-    ldflags = pkg_config('libcrypto', '--libs', extra_pc_dir=extra_pc_dir)
-    # Workaround bug in homebrew openssl package. This bug appears in CI only
-    if is_macos and ldflags and 'homebrew/Cellar' in ldflags[0] and not ldflags[0].endswith('/lib'):
-        ldflags.insert(0, ldflags[0] + '/lib')
-    return cflags, ldflags
 
-
 def at_least_version(package: str, major: int, minor: int = 0) -> None:
     q = f'{major}.{minor}'
     if subprocess.run([PKGCONFIG, package, f'--atleast-version={q}']
@@ -720,6 +700,7 @@ def get_source_specific_defines(env: Env, src: str) ->
     if src == 'kitty/data-types.c':
         if not env.vcs_rev:
             env.vcs_rev = get_vcs_rev()
+            env.ldflags.append('-lutempter')
         return src, [], [f'KITTY_VCS_REV="{env.vcs_rev}"', f'WRAPPED_KITTENS="{wrapped_kittens()}"']
     if src.startswith('3rdparty/base64/'):
         return src, ['3rdparty/base64',], base64_defines(env.binary_arch.isa)
@@ -1326,8 +1307,8 @@ def create_linux_bundle_gunk(ddir: str, args: Options)
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

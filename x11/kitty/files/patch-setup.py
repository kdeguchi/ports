--- setup.py.orig	2023-07-13 16:10:52 UTC
+++ setup.py
@@ -130,27 +130,11 @@ def libcrypto_flags() -> Tuple[List[str], List[str]]:
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
-            if not openssl_dirs:
-                raise SystemExit(f'Failed to find OpenSSL version {v[0]}.{v[1]} on your system')
-            extra_pc_dir = os.pathsep.join(openssl_dirs)
-        cflags = pkg_config('libcrypto', '--cflags-only-I', extra_pc_dir=extra_pc_dir)
-    return cflags, pkg_config('libcrypto', '--libs', extra_pc_dir=extra_pc_dir)
 
-
 def at_least_version(package: str, major: int, minor: int = 0) -> None:
     q = f'{major}.{minor}'
     if subprocess.run([PKGCONFIG, package, f'--atleast-version={q}']
@@ -538,6 +522,7 @@ def get_source_specific_defines(env: Env, src: str) ->
     if src == 'kitty/data-types.c':
         if not env.vcs_rev:
             env.vcs_rev = get_vcs_rev()
+        env.ldflags.append('-lutempter')
         return src, [f'KITTY_VCS_REV="{env.vcs_rev}"', f'WRAPPED_KITTENS="{wrapped_kittens()}"']
     try:
         return src, env.library_paths[src]
@@ -1163,7 +1148,8 @@ def create_linux_bundle_gunk(ddir: str, libdir_name: s
                 raise SystemExit(f'kitten binary not found at: {kitten_exe}')
     if not skip_docs
         copy_man_pages(ddir)
-        copy_html_docs(ddir)
+    if os.getenv('BUILD_DOCS') == 'yes':
+        copy_html_docs(ddir)
     for (icdir, ext) in {'256x256': 'png', 'scalable': 'svg'}.items():
         icdir = os.path.join(ddir, 'share', 'icons', 'hicolor', icdir, 'apps')
         safe_makedirs(icdir)

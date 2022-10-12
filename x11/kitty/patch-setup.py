--- setup.py.orig	2022-09-20 00:59:54 UTC
+++ setup.py
@@ -147,8 +147,15 @@ def libcrypto_flags() -> Tuple[List[str], List[str]]:
             if not openssl_dirs:
                 raise SystemExit(f'Failed to find OpenSSL version {v[0]}.{v[1]} on your system')
             extra_pc_dir = os.pathsep.join(openssl_dirs)
-        cflags = pkg_config('libcrypto', '--cflags-only-I', extra_pc_dir=extra_pc_dir)
-    return cflags, pkg_config('libcrypto', '--libs', extra_pc_dir=extra_pc_dir)
+    #try:
+    #    cflags = pkg_config('libcrypto', '--cflags-only-I', extra_pc_dir=extra_pc_dir)
+    #except subprocess.CalledProcessError:
+        cflags = [ '-I/usr/include' ]
+    #try:
+    #    ldflags = pkg_config('libcrypto', '--libs', extra_pc_dir=extra_pc_dir)
+    #except subprocesses.CalledProcessError:
+        ldflags = [ '-L/usr/lib', '-lcrypto' ]
+    return cflags, ldflags
 
 
 def at_least_version(package: str, major: int, minor: int = 0) -> None:

--- src/bazel/pkg_config_repository.bzl	2022-07-23 23:02:59.000000000 +0900
+++ src/bazel/pkg_config_repository.bzl	2022-08-05 18:51:57.036618000 +0900
@@ -71,6 +71,9 @@ cc_library(
     linkopts = [
         {linkopts}
     ],
+    srcs = [
+        {srcs}
+    ]
 )
 """
 
@@ -100,16 +103,32 @@ def _pkg_config_repository_impl(repo_ctx):
         repo_ctx.symlink("/" + path, path)
 
 def _pkg_config_repository_impl(repo_ctx):
+    # includedir
     includes = _exec_pkg_config(repo_ctx, "--cflags-only-I")
     includes = [item[len("-I/"):] for item in includes]
     _symlinks(repo_ctx, includes)
+    includedirs = [item[len("/"):] for item in repo_ctx.attr.includedirs]
+    includes.extend(includedirs)
+    # libdir
+    linkopts = _exec_pkg_config(repo_ctx, "--libs-only-l")
+    libdirs = _exec_pkg_config(repo_ctx, "--libs-only-L")
+    libdirs = [item[len("-L/"):] for item in libdirs]
+    libdir = "".join(libdirs)
+    # lib*.so
+    srcs = [libdir + '/lib' + linkopt[len("-l"):] + '.so' for linkopt in linkopts]
+    _symlinks(repo_ctx, srcs)
+    # symlinks
+    symlinks = repo_ctx.attr.symlinks
+    symlinks = [item[len("/"):] for item in symlinks]
+    _symlinks(repo_ctx, symlinks)
     data = {
         # In bzlmod, repo_ctx.attr.name has a prefix like "_main~_repo_rules~ibus".
         "name": repo_ctx.attr.name.split("~")[-1],
         "hdrs": _make_strlist([item + "/**" for item in includes]),
         "copts": _make_strlist(_exec_pkg_config(repo_ctx, "--cflags-only-other")),
         "includes": _make_strlist(includes),
-        "linkopts": _make_strlist(_exec_pkg_config(repo_ctx, "--libs-only-l")),
+        "linkopts": _make_strlist(linkopts),
+        "srcs": _make_strlist(srcs),
     }
     build_file_data = BUILD_TEMPLATE.format(**data)
 
@@ -126,5 +145,7 @@ pkg_config_repository = repository_rule(
     local = True,
     attrs = {
         "packages": attr.string_list(),
+        "includedirs": attr.string_list(),
+        "symlinks": attr.string_list(),
     },
 )

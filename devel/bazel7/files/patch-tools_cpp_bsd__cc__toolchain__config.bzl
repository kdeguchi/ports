--- tools/cpp/bsd_cc_toolchain_config.bzl.orig	1979-12-31 15:00:00 UTC
+++ tools/cpp/bsd_cc_toolchain_config.bzl
@@ -111,6 +111,8 @@ def _impl(ctx):
                             "-D__DATE__=\"redacted\"",
                             "-D__TIMESTAMP__=\"redacted\"",
                             "-D__TIME__=\"redacted\"",
+                            "-Wno-gnu-offsetof-extensions",
+                            "-Wno-c23-extensions",
                         ],
                     ),
                 ],

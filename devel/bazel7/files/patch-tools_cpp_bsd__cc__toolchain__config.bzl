--- tools/cpp/bsd_cc_toolchain_config.bzl.orig	1979-12-31 15:00:00 UTC
+++ tools/cpp/bsd_cc_toolchain_config.bzl
@@ -111,6 +111,7 @@ def _impl(ctx):
                             "-D__DATE__=\"redacted\"",
                             "-D__TIMESTAMP__=\"redacted\"",
                             "-D__TIME__=\"redacted\"",
+                            "-Wno-gnu-offsetof-extensions",
                         ],
                     ),
                 ],
@@ -134,6 +135,7 @@ def _impl(ctx):
                             "-fstack-protector",
                             "-Wall",
                             "-fno-omit-frame-pointer",
+                            "-Wno-gnu-offsetof-extensions",
                         ],
                     ),
                 ],
@@ -153,6 +155,7 @@ def _impl(ctx):
                             "-DNDEBUG",
                             "-ffunction-sections",
                             "-fdata-sections",
+                            "-Wno-gnu-offsetof-extensions",
                         ],
                     ),
                 ],

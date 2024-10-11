--- scripts/bootstrap/bootstrap.sh.orig	2024-10-11 00:06:41 UTC
+++ scripts/bootstrap/bootstrap.sh
@@ -35,7 +35,7 @@ _BAZEL_ARGS="--spawn_strategy=standalone \
 #  mirrored. See https://github.com/bazelbuild/bazel/pull/19549 for more context.
 _BAZEL_ARGS="--spawn_strategy=standalone \
       --nojava_header_compilation \
-      --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+      --strategy=Javac=standalone --ignore_unsupported_sandboxing --curses=no \
       --compilation_mode=opt \
       --repository_cache=derived/repository_cache \
       --repo_env=BAZEL_HTTP_RULES_URLS_AS_DEFAULT_CANONICAL_ID=0 \

--- cmake/ConkyPlatformChecks.cmake.orig	2022-10-16 17:06:21 UTC
+++ cmake/ConkyPlatformChecks.cmake
@@ -355,6 +355,9 @@ endif(BUILD_X11)
 # Otherwise, use the most recent Lua version
 pkg_search_module(LUA
                   REQUIRED
+                  lua5.4
+                  lua-5.4
+                  lua54
                   lua>=5.3
                   lua5.3
                   lua-5.3

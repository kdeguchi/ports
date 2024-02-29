--- cmake/ConkyBuildOptions.cmake.orig	2021-04-26 14:48:46 UTC
+++ cmake/ConkyBuildOptions.cmake
@@ -73,7 +73,7 @@ if(BUILD_I18N)
 endif(BUILD_I18N)
 
 # Some standard options
-set(SYSTEM_CONFIG_FILE "/etc/conky/conky.conf"
+set(SYSTEM_CONFIG_FILE "%%LOCALBASE%%/etc/conky/conky.conf"
   CACHE STRING "Default system-wide Conky configuration file")
 
 # use FORCE below to make sure this changes when CMAKE_INSTALL_PREFIX is

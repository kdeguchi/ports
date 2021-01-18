--- cmake/ConkyBuildOptions.cmake.orig	2019-01-08 01:26:24 UTC
+++ cmake/ConkyBuildOptions.cmake
@@ -260,6 +260,8 @@ option(BUILD_JOURNAL "Enable support for reading from the systemd journal"
 option(BUILD_PULSEAUDIO
       "Enable support for Pulseaudio's default sink and source" false)

+option(BUILD_HSV_GRADIENT "Enable gradient in HSV colour space" true)
+
 message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})
 message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})


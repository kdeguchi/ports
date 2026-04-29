--- configure.cmake.orig	2026-01-20 08:51:38 UTC
+++ configure.cmake
@@ -4,6 +4,11 @@ include(${CMAKE_CURRENT_LIST_DIR}/src/qdoc/cmake/QDocC
 # Include QDoc-specific configuration early (needed for feature definitions)
 include(${CMAKE_CURRENT_LIST_DIR}/src/qdoc/cmake/QDocConfiguration.cmake)
 
+#### Libraries
+
+qt_find_package(WrapZSTD 1.3 PROVIDED_TARGETS WrapZSTD::WrapZSTD MODULE_NAME designer)
+
+
 #### Tests
 
 qt_find_package(WrapLibClang 8 PROVIDED_TARGETS WrapLibClang::WrapLibClang)

--- avidemux_core/ADM_core/include/ADM_assert.h.orig	2024-10-09 22:56:11 UTC
+++ avidemux_core/ADM_core/include/ADM_assert.h
@@ -61,7 +61,7 @@ ADM_CORE6_EXPORT void            ADM_usleep(unsigned l
 /* */
 ADM_CORE6_EXPORT void            ADM_usleep(unsigned long us);
 
-#ifndef __APPLE__
+#if !defined (__APPLE__) && !defined(_FreeBSD__)
   typedef void *(* adm_fast_memcpy)(void *to, const void *from, size_t len);
   extern ADM_CORE6_EXPORT adm_fast_memcpy myAdmMemcpy;
 #endif
@@ -69,7 +69,7 @@ ADM_CORE6_EXPORT void            ADM_usleep(unsigned l
 
 #define ADM_dealloc(x) ADM_dezalloc( (void *)x)
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined( __FreeBSD__)
   #define memcpy myAdmMemcpy
 #endif
 
@@ -83,10 +83,10 @@ ADM_CORE6_EXPORT void            ADM_usleep(unsigned l
         #define NO_ADM_MEMCHECK
 #endif
 
-  
+
 #ifdef __cplusplus
 }
-  
+
 #endif
 
 // ADM_cleanupPath returns a cleaned up copy of the parameter

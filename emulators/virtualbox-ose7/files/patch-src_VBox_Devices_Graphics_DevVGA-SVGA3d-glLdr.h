--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-glLdr.h.orig	2024-10-10 18:28:58 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-glLdr.h
@@ -346,7 +346,7 @@ GLPFN BOOL (WINAPI *pfn_wglShareLists)(HGLRC, HGLRC);
 GLPFN BOOL (WINAPI *pfn_wglShareLists)(HGLRC, HGLRC);
 #define wglShareLists pfn_wglShareLists
 
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /*
  * GLX
  */
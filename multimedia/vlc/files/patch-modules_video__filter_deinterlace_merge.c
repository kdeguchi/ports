--- modules/video_filter/deinterlace/merge.c.orig	2026-05-24 15:35:12 UTC
+++ modules/video_filter/deinterlace/merge.c
@@ -34,7 +34,9 @@
 #include "merge.h"
 
 #ifdef HAVE_ALTIVEC_H
+#   undef bool
 #   include <altivec.h>
+#   define bool _Bool
 #endif
 
 /*****************************************************************************

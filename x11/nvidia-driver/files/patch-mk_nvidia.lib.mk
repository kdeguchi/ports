--- mk/nvidia.lib.mk.orig	2020-09-23 00:45:08 UTC
+++ mk/nvidia.lib.mk
@@ -52,8 +52,8 @@ install: ${EXTRADEPS}
 .endif
 .endif
 .if defined(AUXLINK_TGT)
-	@rm -f ${AUXLINK_LINK}
-	@ln -fs ${AUXLINK_TGT} ${AUXLINK_LINK}
+	@rm -f ${DESTDIR}${AUXLINK_LINK}
+	@ln -fs ${AUXLINK_TGT} ${DESTDIR}${AUXLINK_LINK}
 .endif
 .if defined(STATICLIB_NAME)
 	@rm -f ${DESTDIR}${THISLIBDIR}/${STATICLIB_NAME}

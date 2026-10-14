--- compiler_flags.mk
+++ compiler_flags.mk
@@ -7,6 +7,13 @@
 CFLAGS+=	-include ${SYSDIR}/compat/linuxkpi/common/include/linux/compiler_types.h
 .endif
 
+# Other headers are always included. See the definition of `$(USERINCLUDE)` in
+# the Makefile at the root of the Linux source tree.
+.if exists(${SYSDIR}/compat/linuxkpi/common/include/linux/compiler-version.h)
+CFLAGS+=	-include ${SYSDIR}/compat/linuxkpi/common/include/linux/compiler-version.h
+.endif
+CFLAGS+=	-include ${SYSDIR}/compat/linuxkpi/common/include/linux/kconfig.h
+
 CWARNFLAGS+=	-Wno-pointer-sign
 
 # Globally silence a new warning from Clang 21.

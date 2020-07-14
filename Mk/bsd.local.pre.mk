#USES:=	${USES:C@[:,]{0,1}wchar_t@@W}
#USES:=	${USES:C@[:,]{0,1}translit@@W}

.if ! empty(USE_LINUX_APPS:Mtcl84)
USE_LINUX_APPS:=	${USE_LINUX_APPS:S/tcl84/tcl85/}
.endif
.if ! empty(USE_LINUX_APPS:Mtk84)
USE_LINUX_APPS:=	${USE_LINUX_APPS:S/tk84/tk85/}
.endif

#.if ${.CURDIR:M*/emulators/i386-wine-devel*}
#GECKO_RUN_DEPENDS=	${DATADIR}/gecko/wine_gecko-2.36-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel
#MONO_RUN_DEPENDS=	${DATADIR}/mono/wine-mono-4.7.5.msi:${PORTSDIR}/emulators/wine-mono-devel
#.endif

.if ${.CURDIR:M*/graphics/gegl}
USES:=	${USES:S@compiler:c++14-lang@compiler:openmp@}
.endif

.if ${.CURDIR:M*/graphics/ImageMagick6}
USES:=	${USES:S@pkgconfig:both@pkgconfig@}
.if ${PORT_OPTIONS:MOPENMP}
USES:=	${USES:S@c++11-lang@openmp@}
.endif
.endif

.if ${.CURDIR:M*/multimedia/libxine}
USES:=	${USES:S@compiler @compiler:openmp @W}
.endif

.if ${.CURDIR:M*/devel/p5-ExtUtils-PkgConfig}
USES:=	${USES:S@pkgconfig:both@pkgconfig@}
.endif

.if defined(BUILD_DEPENDS) && ${BUILD_DEPENDS:M*devel/p5-Glib2}
USES+=	pkgconfig
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:M*devel/p5-Glib2}
USES+=	pkgconfig
.endif

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*devel/p5-Glib2}
USES+=	pkgconfig
.endif

.if defined(BUILD_DEPENDS) && ${BUILD_DEPENDS:M*x11/libXdmcp}
USE_XORG+=	xorgproto
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:M*x11/libXdmcp}
USE_XORG+=	xorgproto
.endif

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*x11/libXdmcp}
USE_XORG+=	xorgproto
.endif

.if defined(BUILD_DEPENDS) && ${BUILD_DEPENDS:M*graphics/cairo}
OPENGL_USE+=	xorg=xorgproto
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:M*graphics/cairo}
OPENGL_USE+=	xorg=xorgproto
.endif

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*graphics/cairo}
OPENGL_USE+=	xorg=xorgproto
.endif

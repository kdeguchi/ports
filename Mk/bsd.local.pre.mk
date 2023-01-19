.if ${.CURDIR:M*/graphics/ImageMagick*}
USES:=	${USES:S@pkgconfig:both@pkgconfig@}
.endif

.if ${.CURDIR:M*/devel/p5-ExtUtils-PkgConfig}
USES:=	${USES:S@pkgconfig:both@pkgconfig@}
.endif

.if defined(BUILD_DEPENDS) && ( ${BUILD_DEPENDS:M*graphics/ImageMagick*} || ${BUILD_DEPENDS:M*devel/p5-Glib2} || ${BUILD_DEPENDS:M*devel/p5-ExtUtils-PkgConfig} )
USES+=	pkgconfig
.endif

.if defined(LIB_DEPENDS) && ( ${LIB_DEPENDS:M*graphics/ImageMagick*} || ${LIB_DEPENDS:M*devel/p5-Glib2} || ${LIB_DEPENDS:M*devel/p5-ExtUtils-PkgConfig} )
USES+=	pkgconfig
.endif

.if defined(RUN_DEPENDS) && ( ${RUN_DEPENDS:M*graphics/ImageMagick*} || ${RUN_DEPENDS:M*devel/p5-Glib2} || ${RUN_DEPENDS:M*devel/p5-ExtUtils-PkgConfig} )
USES+=	pkgconfig
.endif

.if defined(USE_KDE) && ${USE_KDE:Mecm}
USE_KDE:=	${USE_KDE:S@ecm@ecm:build@}
.endif

.if defined(USE_KDE) && ${USE_KDE:Mkirigami2}
USE_KDE:=	${USE_KDE:S@kirigami2@kirigami2:build@}
.endif

.if defined(USE_KDE) && ${USE_KDE:Mplasma-wayland-protocols}
USE_KDE:=	${USE_KDE:S@plasma-wayland-protocols@plasma-wayland-protocols:build@}
.endif

.if ${.CURDIR:M*/sysutils/libcdio-paranoia}
USES+=	iconv
.endif

.if ${.CURDIR:M*/graphics/libetonyek01}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libboost_filesystem.so:devel/boost-libs@@}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/container/small_vector.hpp:devel/boost-libs
.endif

.if ${.CURDIR:M*/math/lib2geom}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libboost_thread.so:devel/boost-libs@@}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/container/small_vector.hpp:devel/boost-libs
.endif

.if ${.CURDIR:M*/devel/llvm*}
USES:=	${USES:S/lua:53/lua:54/}
.endif

.if ${.CURDIR:M*/graphics/libjxl}
USES+=	xorg
USE_XORG=	xorgproto
.endif

SCRITPTSDIR=	/home/deguchi/data/work/github/ports/Mk/Scripts

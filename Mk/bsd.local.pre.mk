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

########################################
# KDE
########################################
.if defined(USE_KDE) && ${USE_KDE:Mecm}
USE_KDE:=	${USE_KDE:S@ecm@ecm:build@}
.endif

.if defined(USE_KDE) && ! ${USE_KDE:Mecm\:build}
USE_KDE+=	ecm:build
.endif

.if defined(USE_KDE) && ${USE_KDE:Mplasma-wayland-protocols}
USE_KDE:=	${USE_KDE:S@plasma-wayland-protocols@plasma-wayland-protocols:build@}
.endif

########################################
# xorgproto
########################################
.if defined(USES)&& ( ${USES:M*pkgconfig} || ${USES:M*xorg} || ${USES:M*gl} || ${USES:M*gnome})
. if ! ${.CURDIR:M*x11/xorgproto}
USES+=	xorg
USE_XORG+=	xorgproto
USE_XORG:=	${USE_XORG:S@xorgproto:both@xorgproto@}
. endif
.endif

########################################
# pkgconf
########################################
.if ${.CURDIR:M*/graphics/ImageMagick*}
USES:=	${USES:S@pkgconfig:both@pkgconfig@}
.endif

.if ${.CURDIR:M*/devel/p5-ExtUtils-PkgConfig}
USES:=	${USES:S@pkgconfig:both@pkgconfig@}
.endif

.if defined(BUILD_DEPENDS) && ( ${BUILD_DEPENDS:M*graphics/ImageMagick*} || ${BUILD_DEPENDS:M*devel/p5-Glib2} || ${BUILD_DEPENDS:M*devel/p5-ExtUtils-PkgConfig} )
. if ! ${USES:Mpkgconfig}
USES+=	pkgconfig
. endif
.endif

.if defined(LIB_DEPENDS) && ( ${LIB_DEPENDS:M*graphics/ImageMagick*} || ${LIB_DEPENDS:M*devel/p5-Glib2} || ${LIB_DEPENDS:M*devel/p5-ExtUtils-PkgConfig} )
. if ! ${USES:Mpkgconfig}
USES+=	pkgconfig
. endif
.endif

.if defined(RUN_DEPENDS) && ( ${RUN_DEPENDS:M*graphics/ImageMagick*} || ${RUN_DEPENDS:M*devel/p5-Glib2} || ${RUN_DEPENDS:M*devel/p5-ExtUtils-PkgConfig} )
. if ! ${USES:Mpkgconfig}
USES+=	pkgconfig
. endif
.endif

SCRITPTSDIR=	/home/deguchi/data/work/github/ports/Mk/Scripts

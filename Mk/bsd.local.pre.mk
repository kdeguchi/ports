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

.if ${.CURDIR:M*/devel/glib20} || ${.CURDIR:M*/graphics/inkscape} || \
	${.CURDIR:M*/comms/hidapi}
USES:=	${USES:S@:wchar_t@@}
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

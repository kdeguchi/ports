.if ${.CURDIR:M*/devel/ccache*}
NO_CCACHE=	yes
NO_SCCACHE=	yes
.endif

#.if defined(BUILD_DEPENDS) && ${BUILD_DEPENDS:M*lang/rust*}
#.undef NO_SCCACHE
#. if ! defined(CCACHE_DIR)
#SCCACHE_DIR!=	/usr/local/bin/ccache -p | awk ' /cache_dir = / { print $$4 } '
#. endif
#_USES_configure:=	${_USES_configure:S@250:sccache-start@@}
#_USES_stage:=	${_USES_stage:S@950:sccache-stats@@}
#.else
#NO_SCCACHE=	yes
#.endif

#.if exists(/usr/local/share/sccache/overlay)
#OVERLAYS+=	/usr/local/share/sccache/overlay
#.endif

.if ${.CURDIR:M*/sysutils/libcdio-paranoia*}
USES+=	iconv
.endif

.if ${.CURDIR:M*/graphics/libetonyek01*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libboost_filesystem.so:devel/boost-libs@@}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/container/small_vector.hpp:devel/boost-libs
.endif

.if ${.CURDIR:M*/math/lib2geom*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libboost_thread.so:devel/boost-libs@@}
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/container/small_vector.hpp:devel/boost-libs
.endif

.if ${.CURDIR:M*/devel/llvm*}
LLDB_USES:=	${LLDB_USES:S/lua:53/lua:54/}
.endif

.if ${.CURDIR:M*/security/veracrypt}
USE_WX=	3.2
.endif

########################################
# KDE
########################################
.if defined(USE_KDE) && ${USE_KDE:M*ecm*}
#NO_CCACHE=	yes
. if defined(USE_KDE) && ! ${USE_KDE:M*ecm\:build*}
USE_KDE:=	${USE_KDE:S@ecm@ecm:build@}
. endif
.endif

########################################
# QT
########################################
.if defined(USE_QT) && ${USE_QT:M*designer*}
. if defined(USE_QT) && ! ${USE_QT:M*designer\:build*}
USE_QT:=	${USE_QT:S@designer@designer:build@}
. endif
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

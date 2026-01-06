# this file is included by ${PORTSDIR}/Mk/bsd.local.mk
# Local_Post_Include

.if defined(_UNRAR_ICONV) && exists(${PORTSDIR}/archivers/unrar-iconv)
EXTRACT_DEPENDS:=	${EXTRACT_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
BUILD_DEPENDS:=		${BUILD_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
LIB_DEPENDS:=		${LIB_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
RUN_DEPENDS:=		${RUN_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
.endif

.if defined(_XFCE4_NOTIFYD) && exists(${PORTSDIR}/deskutils/xfce4-notifyd)
RUN_DEPENDS:=	${RUN_DEPENDS:C@${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon$@${LOCALBASE}/lib/xfce4/notifyd/xfce4-notifyd:deskutils/xfce4-notifyd@}
RUN_DEPENDS:=	${RUN_DEPENDS:C@notification-daemon>0:deskutils/notification-daemon@${LOCALBASE}/lib/xfce4/notifyd/xfce4-notifyd:deskutils/xfce4-notifyd@}
.endif

.if defined(CC) && ${CC:M/usr/bin/clang}
CC=	clang
.endif

.if defined(CXX) && ${CXX:M/usr/bin/clang++}
CXX=	clang++
.endif

.if defined(CPP) && ${CPP:M/usr/bin/clang-cpp}
CPP=	clang-cpp
.endif

.if defined(CC) && ${CC:M${PREFIX}/bin/clang${LLVM_DEFAULT}}
CC=	clang${LLVM_DEFAULT}
.endif

.if defined(CXX) && ${CXX:M${PREFIX}/bin/clang++${LLVM_DEFAULT}}
CXX=	clang++${LLVM_DEFAULT}
.endif

.if defined(CPP) && ${CPP:M${PREFIX}/bin/clang-cpp${LLVM_DEFAULT}}
CPP=	clang-cpp${LLVM_DEFAULT}
.endif

.if defined(CC) && ${CC:M/usr/bin/gcc}
CC=	gcc
.endif

.if defined(CXX) && ${CXX:M/usr/bin/g++}
CXX=	g++
.endif

.if defined(CPP) && ${CPP:M/usr/bin/gcpp}
CPP=	gcpp
.endif

.if defined(CC) && ${CC:M/usr/bin/cc}
CC=	cc
.endif

.if defined(CXX) && ${CXX:M/usr/bin/c++}
CXX=	c++
.endif

.if defiend(CPP) && ${CPP:M/usr/bin/cpp}
CPP=	cpp
.endif

#.if defined(CC) && ${CC:T:Mclang}
#CFLAGS+=	-Qunused-arguments
#.endif

########################################
# misc
########################################
.if defined(USE_GECKO) # firefox, thunderbird etc.
. if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
MOZ_OPTIONS+=	--with-ccache
. endif
.endif

.if ${.CURDIR:M*/math/maxima*}
NOUSERINIT_EXTRA_PATCHES_OFF=
.endif

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*sudo\:security/sudo*}
RUN_DEPENDS:=	${RUN_DEPENDS:S@sudo:security/sudo@sudo:security/doas-wrapper@}
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:M*\:x11-toolkits/Xaw3d*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@x11-toolkits/Xaw3d@x11-toolkits/libXaw3d@}
.endif

.if ${.CURDIR:M*/graphics/evince*}
MESON_ARGS+=	-Dthumbnail_cache=disabled
.endif

.if ${.CURDIR:M*/editors/libreoffice}
RUN_DEPENDS:=	${RUN_DEPENDS:C@.*/GentiumBasic/.*@${LOCALBASE}/share/fonts/Gentium/Gentium-Regular.ttf:x11-fonts/gentium@}
.endif

.if defined(PREFIX) && ${PREFIX} == /usr/local
POST_PLIST+=	remove-info-plist
. if ! ${.CURDIR:M*/math/maxima}
.  if !target(remove-info-plist)
.undef INFO
remove-info-plist:
	cd ${STAGEDIR}${PREFIX} && \
		${FIND} share/info/ \( -type f -or -type l \) -exec ${RM} -r {} + && \
		${REINPLACE_CMD} -E '/share\/info\/.*$$/d' ${TMPPLIST} || exit 0
.  endif
. endif
.endif

# Support sys/inotify.h
# libinotify.so is conflict with libc in FreeBSD 15
.if exists(/usr/include/sys/inotify.h)
. if defined(LIB_DEPENDS) && ${LIB_DEPENDS:Mlibinotify*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libinotify.so:devel/libinotify@@}
. endif
.endif

SCRIPTSDIR=	${OVERLAYS:[1]}/Mk/Scripts

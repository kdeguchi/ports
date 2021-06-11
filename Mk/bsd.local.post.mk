# this file is included by ${PORTSDIR}/Mk/bsd.local.mk
# Local_Post_Include

.if defined(_UNRAR_ICONV) && exists(${PORTSDIR}/archivers/unrar-iconv)
EXTRACT_DEPENDS:=	${EXTRACT_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
BUILD_DEPENDS:=		${BUILD_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
LIB_DEPENDS:=		${LIB_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
RUN_DEPENDS:=		${RUN_DEPENDS:S@archivers/unrar$@archivers/unrar-iconv@}
.endif

.if defined(_LV) && exists(${PORTSDIR}/misc/lv)
BUILD_DEPENDS:=	${BUILD_DEPENDS:S@jless:japanese/less@lv:misc/lv@}
LIB_DEPENDS:=	${LIB_DEPENDS:S@jless:japanese/less@lv:misc/lv@}
RUN_DEPENDS:=	${RUN_DEPENDS:S@jless:japanese/less@lv:misc/lv@}
.endif

.if defined(_XFCE4_NOTIFYD) && exists(${PORTSDIR}/deskutils/xfce4-notifyd)
RUN_DEPENDS:=	${RUN_DEPENDS:C@${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon$@${LOCALBASE}/lib/xfce4/notifyd/xfce4-notifyd:deskutils/xfce4-notifyd@}
RUN_DEPENDS:=	${RUN_DEPENDS:C@notification-daemon>0:deskutils/notification-daemon@${LOCALBASE}/lib/xfce4/notifyd/xfce4-notifyd:deskutils/xfce4-notifyd@}
.endif

LIB_DEPENDS:=	${LIB_DEPENDS:C@libMagick(.*)-6.Q16.so@libMagick\1-6.Q16*.so@}
RUN_DEPENDS:=	${RUN_DEPENDS:C@p5-Gtk>@p5-Gtk-Perl>@}
RUN_DEPENDS:=	${RUN_DEPENDS:C@/p5-Gtk$@/p5-Gtk-Perl@}

.if ${CC:M/usr/bin/clang}
CC=	clang
.endif

.if ${CXX:M/usr/bin/clang++}
CXX=	clang++
.endif

.if ${CPP:M/usr/bin/clang-cpp}
CPP=	clang-cpp
.endif

.if ${CC:M${PREFIX}/bin/clang${LLVM_DEFAULT}}
CC=	clang${LLVM_DEFAULT}
.endif

.if ${CXX:M${PREFIX}/bin/clang++${LLVM_DEFAULT}}
CXX=	clang++${LLVM_DEFAULT}
.endif

.if ${CPP:M${PREFIX}/bin/clang-cpp${LLVM_DEFAULT}}
CPP=	clang-cpp${LLVM_DEFAULT}
.endif

.if ${CC:M/usr/bin/gcc}
CC=	gcc
.endif

.if ${CXX:M/usr/bin/g++}
CXX=	g++
.endif

.if ${CPP:M/usr/bin/gcpp}
CPP=	gcpp
.endif

.if ${CC:M/usr/bin/cc}
CC=	cc
.endif

.if ${CXX:M/usr/bin/c++}
CXX=	c++
.endif

.if ${CPP:M/usr/bin/cpp}
CPP=	cpp
.endif

.if defined(CC) && ${CC:T:Mclang}
CFLAGS+=	-Qunused-arguments
.endif

.if ${.CURDIR:M*/chinese/fcitx}
USE_KDE:=	${USE_KDE:S@ecm@ecm_build@}
.endif

#.if ${.CURDIR:M*/x11/xfce4-terminal}
#CONFIGURE_ARGS+=	--with-utempter
#.endif

.if ${.CURDIR:M*/databases/mariadb*-server}
SUB_LIST+=	MARIADB_GROUP="${MARIADB_GROUP}"
.endif

.if ${.CURDIR:M*/sysutils/fusefs-lkl}
RUN_DEPENDS:=	${RUN_DEPENDS:C@gcc[0-9]+:lang/gcc[0-9]+@@}
.endif

.if ${.CURDIR:M*/multimedia/*x264}
RUN_DEPENDS:=	${RUN_DEPENDS:C@gcc[0-9]+:lang/gcc[0-9]+@@}
.endif

.if ${.CURDIR:M*/multimedia/vapoursynth}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libavcodec.so:multimedia/ffmpeg@@}
.endif

.if ${.CURDIR:M*/devel/qt5-core}
RUN_DEPENDS:=	${RUN_DEPENDS:S@etc_os-release>0:sysutils/etc_os-release@@}
.endif

.if ${.CURDIR:M*/emulators/i386-wine-devel}
FETCH_BINARY=	curl
FETCH_ARGS=	--proxy socks5://localhost:1090 --fail --insecure --location --remote-time -O
DISABLE_SIZE=	yes
.endif

.if ${.CURDIR:M*/math/wxmaxima}
USE_WX:=	${USE_WX:S@3.0@3.1@}
.endif

.if ${.CURDIR:M*/www/webkit2-gtk3}
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}
.endif

.if ${.CURDIR:M*/net/samba*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libiconv.so:converters/libiconv@@}
.endif

.if ${.CURDIR:M*/www/firefox}
.if defined(CONFIGURE_ENV) && ${CONFIGURE_ENV:N*${PREFIX}/libexec/ccache}
CONFIGURE_ENV:=	${CONFIGURE_ENV:S@PATH=@PATH=${PREFIX}/libexec/ccache:@}
.endif
.if defined(MAKE_ENV) && ${MAKE_ENV:N*${PREFIX}/libexec/ccache}
MAKE_ENV:=	${MAKE_ENV:S@PATH=@PATH=${PREFIX}/libexec/ccache:@}
.endif
.endif

.if ${.CURDIR:M*/devel/ccache*}
.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS+= 11 12
.endif
.endif

.if defined(PREFIX) && ${PREFIX} == /usr/local
POST_PLIST+=	post-generate-plist
.if !target(post-generate-plist)
post-generate-plist:
	cd ${STAGEDIR}${PREFIX}; \
	[ -d man ] && \
	( _MANFILES=$$( ${FIND} man/ -type f -or -type l ); \
		for _F in $${_MANFILES}; do \
			${MKDIR} share/$${_F%/*}; \
			${MV} $${_F} share/$${_F}; \
		done; \
		${REINPLACE_CMD} -E 's|^man/|share/man/|;s| man/| share/man/|;s|%%MANPAGES%%man/|%%MANPAGES%%share/man/|' ${TMPPLIST}; \
	) || exit 0
.endif
.endif

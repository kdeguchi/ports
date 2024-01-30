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

.if defined(CC) && ${CC:T:Mclang}
CFLAGS+=	-Qunused-arguments
.endif

########################################
# misc
########################################
.if ${.CURDIR:M*/databases/mariadb*-server*}
SUB_LIST+=	MARIADB_GROUP="${MARIADB_GROUP}"
.endif

.if ${.CURDIR:M*/sysutils/fusefs-lkl*}
RUN_DEPENDS:=	${RUN_DEPENDS:C@gcc[0-9]+:lang/gcc[0-9]+@@}
.endif

.if ${.CURDIR:M*/multimedia/*x264*}
RUN_DEPENDS:=	${RUN_DEPENDS:C@gcc[0-9]+:lang/gcc[0-9]+@@}
.endif

.if ${.CURDIR:M*/multimedia/vapoursynth*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@libavcodec.so:multimedia/ffmpeg@@}
.endif

.if ${.CURDIR:M*/math/maxima*}
NOUSERINIT_EXTRA_PATCHES_OFF=
.endif

.if ${.CURDIR:M*/www/webkit2-gtk3*}
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}
.endif

.if ${.CURDIR:M*/www/firefox*} || ${.CURDIR:M*/mail/thunderbird*}
.if defined(CONFIGURE_ENV) && ${CONFIGURE_ENV:N*${PREFIX}/libexec/ccache}
CONFIGURE_ENV:=	${CONFIGURE_ENV:S@PATH=@PATH=${PREFIX}/libexec/ccache:@}
.endif
.if defined(MAKE_ENV) && ${MAKE_ENV:N*${PREFIX}/libexec/ccache}
MAKE_ENV:=	${MAKE_ENV:S@PATH=@PATH=${PREFIX}/libexec/ccache:@}
.endif
.endif

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*sudo\:security/sudo*}
RUN_DEPENDS:=	${RUN_DEPENDS:S@sudo:security/sudo@sudo:security/doas-wrapper@}
.endif

.if ${.CURDIR:M*/multimedia/libxine*}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--enable-musepack//}
.endif

.if ${.CURDIR:M*/x11-toolkits/Xaw3d*}
PATH:=/usr/bin:${PATH}
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:M*\:x11-toolkits/Xaw3d*}
LIB_DEPENDS:=	${LIB_DEPENDS:S@x11-toolkits/Xaw3d@x11-toolkits/libXaw3d@}
.endif

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*/security/veracrypt*}
.if !target(pre-configure)
pre-configure:
	${REINPLACE_CMD} -e 's|Icon=VeraCrypt-16x16|Icon=VeraCrypt-256x256|g' ${WRKSRC}/src/Setup/FreeBSD/veracrypt.desktop
.endif
.endif

.if ${.CURDIR:M*/graphics/gegl*}
MESON_ARGS+=	-Dlibv4l=disabled -Dmrg=disabled
.endif

.if ${.CURDIR:M*/graphics/evince*}
MESON_ARGS+=	-Dthumbnail_cache=disabled
.endif

.if ${.CURDIR:M*/devel/llvm*}
USES:=	${USES:S/lua:53/lua:${LUA_VER_STR}/}
. if !target(post-patch-LLDB-on)
post-patch-LLDB-on:
	${REINPLACE_CMD} -e 's/Lua 5\.3/Lua ${LUA_VER}/' \
		${WRKSRC}/lldb/cmake/modules/FindLuaAndSwig.cmake
	${REINPLACE_CMD} -e 's@lua/5\.3@lua/${LUA_VER}@' \
		${WRKSRC}/lldb/test/API/lua_api/TestLuaAPI.py
. endif
. if !target(post-install-LLDB-on)
post-install-LLDB-on:
	${MV} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/lib/lua/5.3 \
		${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/lib/lua/${LUA_VER}
	${REINPLACE_CMD} -e 's|lua/5\.3|lua/${LUA_VER}|' ${TMPPLIST} || exit 0
. endif
.endif

.if defined(BUILD_DEPENDS) && ! ${BUILD_DEPENDS:M*lang/rust}
. if ! ${.CURDIR:M*/lang/rust}
NO_SCCACHE=	yes
.  if defined(NO_CCACHE)
SCCACHE_DIR!=	/usr/local/bin/ccache -p | awk ' /cache_dir = / { print $$4 } '
.  endif
_USES_configure:=	${_USES_configure:S@250:sccache-start@@}
_USES_stage:=	${_USES_stage:S@950:sccache-stats@@}
. endif
.endif

.if defined(PREFIX) && ${PREFIX} == /usr/local
#POST_PLIST+=	remove-info-plist
POST_PLIST+=	post-man-plist remove-info-plist
. if !target(post-man-plist)
post-man-plist:
	cd ${STAGEDIR}${PREFIX}; \
	[ -d man ] && \
	( _MANFILES=$$( ${FIND} man/ -type f -or -type l ); \
		for _F in $${_MANFILES}; do \
			${MKDIR} share/$${_F%/*}; \
			${MV} $${_F} share/$${_F}; \
		done; \
		${REINPLACE_CMD} -E 's|^man/|share/man/|;s| man/| share/man/|;s|%%MANPAGES%%man/|%%MANPAGES%%share/man/|' ${TMPPLIST}; \
	) || exit 0
. endif
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

SCRIPTSDIR=	/home/deguchi/data/work/github/ports/Mk/Scripts

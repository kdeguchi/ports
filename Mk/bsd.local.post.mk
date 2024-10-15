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

.if defined(RUN_DEPENDS) && ${RUN_DEPENDS:M*/security/veracrypt*}
. if !target(pre-configure)
pre-configure:
	${REINPLACE_CMD} -e 's|Icon=VeraCrypt-16x16|Icon=VeraCrypt-256x256|g' ${WRKSRC}/src/Setup/FreeBSD/veracrypt.desktop
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

.if exists(/usr/local/share/sccache/overlay/Mk/bsd.overlay.mk)
. if ( defined(USES) && ${USES:Mcargo} || defined(BUILD_DEPENDS) && ${BUILD_DEPENDS:M*rust*} )
.unexport NO_SCCACHE
.undef NO_SCCACHE
. else
.export NO_SCCACHE=	yes
. endif
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

SCRIPTSDIR=	${OVERLAYS:[1]}/Mk/Scripts

PORTNAME=	sccache
PORTVERSION=	0.12.0
CATEGORIES=	ports-mgmt
MASTER_SITES=
PKGNAMESUFFIX=	-overlay
DISTFILES=

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Ports overlay for sccache
WWW=		https://github.com/mozilla/sccache

BUILD_DEPENDS=	sccache:devel/sccache

LICENSE=	APACHE20

NO_CONFIGURE=	yes
NO_BUILD=	yes

_CCLINKDIR=	libexec/ccache
_GNU_COMPILERS=	12 13 14 15 16
_CLANG_COMPILERS=	12 13 14 15 16 17 18 19 20 21
_CCACHE_COMPILERS=	cc c++ CC clang clang++ \
			gcc g++ ${_GNU_COMPILERS:S|^|gcc|} ${_GNU_COMPILERS:S|^|g++|} ${_GNU_COMPILERS:S|^|cpp|} \
			${_CLANG_COMPILERS:S|^|clang|} ${_CLANG_COMPILERS:S|^|clang++|}

SUB_FILES=	ccache-update-links.sh pkg-message world-ccache
SUB_LIST=	CCLINKDIR="${_CCLINKDIR}" \
		CCACHE_COMPILERS="${_CCACHE_COMPILERS}"
PLIST_FILES=	${DATADIR}/overlay/Mk/bsd.overlay.mk \
		${DATADIR}/overlay/bin/ccache-update-links \
		${DATADIR}/overlay/bin/sccache \
		${DATADIR}/overlay/${_CCLINKDIR}/world/ccache

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/overlay/Mk \
		${STAGEDIR}${DATADIR}/overlay/bin \
		${STAGEDIR}${DATADIR}/overlay/${_CCLINKDIR}/world
	${INSTALL_DATA} ${FILESDIR}/Mk/bsd.overlay.mk \
		${STAGEDIR}${DATADIR}/overlay/Mk
	${CP} ${LOCALBASE}/bin/sccache \
		${STAGEDIR}${DATADIR}/overlay/bin
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${STAGEDIR}${DATADIR}/overlay/bin/ccache-update-links
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${STAGEDIR}${DATADIR}/overlay/${_CCLINKDIR}/world/ccache

.include <bsd.port.mk>

PORTNAME=	foreign-cdm
PORTVERSION=	20231217
PORTREVISION=	3
CATEGORIES=	www multimedia linux
MASTER_SITES=	https://arrowd.name/:cdm
DISTFILES=	cdm-${CDM_INT_HASH}.tar.gz:cdm

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	CDM agent for Chromium
WWW=		https://github.com/shkhln/foreign-cdm

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

FLAVORS=	c7 rl9
FLAVOR=	${LINUX_DEFAULT}

BUILD_DEPENDS=	cmake:devel/cmake-core

c7_BUILD_DEPENDS=	linux-c7-devtoolset>0:devel/linux-c7-devtoolset
c7_RUN_DEPENDS=	linux_base-c7>0:emulators/linux_base-c7

rl9_BUILD_DEPENDS=	linux-rl9-devtools>0:devel/linux-rl9-devtools \
		linux-rl9-libsigc++20>0:devel/linux-rl9-libsigc++20
rl9_RUN_DEPENDS=	linux_base-rl9>0:emulators/linux_base-rl9

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	foreign-cdm
GH_TAGNAME=	3fe4d7130bb1e0581b5310635515a120f2794b88
GH_TUPLE=	capnproto:capnproto:928c8390d4d562bd32dc79a42eb64e9bdba572d8:capnproto/third_party/capnproto

MAKK_ENV=		MAKE_JOBS_NUMBER=${MAKE_JOBS_NUMBER}
c7_MAKE_ENV=	LINUX_CC=${LINUXBASE}/opt/rh/devtoolset-11/root/usr/bin/g++
rl9_MAKE_ENV=	LINUX_CC=${LINUXBASE}/usr/bin/g++

SUB_FILES=	fcdm-setup-env

PLIST_FILES=	libexec/fcdm-jail \
		libexec/fcdm-worker \
		lib/foreign-cdm/fcdm-fbsd.so \
		share/chromium/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so \
		share/chromium/WidevineCdm/manifest.json \
		share/foreign-cdm/fcdm-setup-env

CDM_INT_HASH=	fef0b5aa1bd31efb88dfab804bdbe614f3d54f28

post-extract:
	${MV} ${WRKDIR}/*.h ${WRKSRC}/third_party/cdm/

post-patch:
	${REINPLACE_CMD} -e 's|chmod a+srX|chmod a+rX|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/fcdm-jail ${STAGEDIR}${PREFIX}/libexec/
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/libexec/fcdm-jail
	${INSTALL_PROGRAM} ${WRKSRC}/build/fcdm-worker ${STAGEDIR}${PREFIX}/libexec/

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/fcdm-setup-env ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/foreign-cdm
	${CP} ${WRKSRC}/build/fcdm-fbsd.so ${STAGEDIR}${PREFIX}/lib/foreign-cdm/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/foreign-cdm/fcdm-fbsd.so

	${MKDIR} ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/_platform_specific/linux_x64
	${LN} -s ${PREFIX}/lib/foreign-cdm/fcdm-fbsd.so ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so
	${LN} -s ${PREFIX}/lib/WidevineCdm/manifest.json ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/manifest.json

.include <bsd.port.mk>

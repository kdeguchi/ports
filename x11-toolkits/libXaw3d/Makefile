PORTNAME=	libXaw3d
PORTVERSION=	1.6.3
CATEGORIES=	x11-toolkits

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-D Athena Widget set that looks like Motif

LICENSE=	MIT

USES=		autoreconf gettext libtool pkgconfig xorg xorg-cat:lib
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xmu xpm xt

SUB_FILES=	pkg-message pkg-post-deinstall pkg-post-install
SUB_LIST=	XAWVER="${XAWVER}"

PKGPOSTINSTALL=	${WRKDIR}/pkg-post-install
PKGPOSTDEINSTALL=	${WRKDIR}/pkg-post-deinstall

XAWVER=	8

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXaw3d.so
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/.${PORTNAME}
	${MV} ${STAGEDIR}${PREFIX}/lib/libXaw3d.* \
		${STAGEDIR}${PREFIX}/lib/.${PORTNAME}

.include <bsd.port.mk>

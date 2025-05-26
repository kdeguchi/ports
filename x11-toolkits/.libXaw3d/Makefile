PORTNAME=	libXaw3d
PORTVERSION=	1.6.6
CATEGORIES=	x11-toolkits

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Xaw3d is the X 3D Athena Widget Set
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:xz xorg xorg-cat:lib
USE_XORG=	x11 xau xext xmu xpm xorgproto xt

CONFIGURE_ARGS=	--without-xmlto

SUB_FILES=	pkg-message pkg-post-deinstall pkg-post-install
XAWVER=		8
SUB_LIST=	XAWVER="${XAWVER}"

PKGPOSTINSTALL=	${WRKDIR}/pkg-post-install
PKGPOSTDEINSTALL=	${WRKDIR}/pkg-post-deinstall

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXaw3d.so
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/.${PORTNAME}
	${MV} ${STAGEDIR}${PREFIX}/lib/libXaw3d.* \
		${STAGEDIR}${PREFIX}/lib/.${PORTNAME}

.include <bsd.port.mk>

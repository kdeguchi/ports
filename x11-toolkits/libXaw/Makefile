PORTNAME=	libXaw
PORTVERSION=	1.0.14
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Athena Widgets library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg xorg-cat:lib
USE_XORG=	x11 xau xext xmu xpm xorgproto xt

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--without-xmlto

SUB_FILES=	pkg-post-deinstall pkg-post-install
PKGPOSTINSTALL=	${WRKDIR}/pkg-post-install
PKGPOSTDEINSTALL=	${WRKDIR}/pkg-post-deinstall

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/.${PORTNAME}
	${MV} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}* \
		${STAGEDIR}${PREFIX}/lib/.${PORTNAME}

.include <bsd.port.mk>

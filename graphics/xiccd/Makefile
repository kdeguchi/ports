PORTNAME=	xiccd
PORTVERSION=	0.3.0
CATEGORIES=	graphics

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Simple bridge between colord and X
WWW=	https://github.com/agalakhov/xiccd

LICENSE=	GPLv3

LIB_DEPENDS=	libcolord.so:graphics/colord \
		libXrandr.so:x11/libXrandr

USES=		autoreconf gnome xorg

USE_GITHUB=	yes
GH_ACCOUNT=	agalakhov
GH_TAGNAME=	b518820

USE_GNOME=	glib20
USE_XORG=	x11

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -E 's@sysconfigdir@sysconfdir@g' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>

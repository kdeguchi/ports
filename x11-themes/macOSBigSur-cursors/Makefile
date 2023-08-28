PORTNAME=	macOS-BigSur-cursors
PORTVERSION=	2.0.0
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/ful1e5/apple_cursor/releases/download/v${PORTVERSION}/
DISTNAME=	macOS-BigSur

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	macOS BigSur Cursors

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${DISTNAME} ${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>

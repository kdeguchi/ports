PORTNAME=	macOSBigSur-cursors
PORTVERSION=	1.1.4
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/ful1e5/apple_cursor/releases/download/v${PORTVERSION}/
DISTNAME=	macOSBigSur

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Capitaine Cursors

LICENSE=	GPLv3

NO_BUILD=	yes

do-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${DISTNAME} ${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>

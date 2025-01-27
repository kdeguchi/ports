PORTNAME=	macOS-cursors
PORTVERSION=	2.0.1
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/ful1e5/apple_cursor/releases/download/v${PORTVERSION}/
DISTFILES=	macOS.tar.xz macOS-White.tar.xz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	macOS Cursors

LICENSE=	GPLv3

USES=	tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKDIR}/macOS && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/macOS
	cd ${WRKDIR}/macOS-White && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/macOS-White

.include <bsd.port.mk>

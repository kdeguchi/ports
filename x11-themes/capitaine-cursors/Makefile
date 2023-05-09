PORTNAME=	capitaine-cursors
DISTVERSION=	4
CATEGORIES=	x11-themes
DISTVERSIONPREFIX=	r

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Capitaine Cursors
WWW=		https://github.com/keeferrourke/capitaine-cursors

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		inkscape:graphics/inkscape \
		xcursorgen:x11/xcursorgen

USE_GITHUB=	yes
GH_ACCOUNT=	keeferrourke
GH_TAGNAME=	f6281e8

NO_ARCH=	yes

do-build:
	cd ${WRKSRC} && \
		${PREFIX}/bin/bash ./build.sh -d xhd -t light && \
		${PREFIX}/bin/bash ./build.sh -d xhd -t dark

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}-white
	cd ${WRKSRC}/dist/dark && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}
	cd ${WRKSRC}/dist/light && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}-white

.include <bsd.port.mk>

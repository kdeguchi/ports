PORTNAME=	capitaine-cursors
DISTVERSIONPREFIX=	r
DISTVERSION=	4
CATEGORIES=	x11-themes

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

_DIRNAME=	Capitaine-Cursors

do-build:
	cd ${WRKSRC} && \
		${PREFIX}/bin/bash ./build.sh -d xhd -t light && \
		${PREFIX}/bin/bash ./build.sh -d xhd -t dark

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/${_DIRNAME} \
		${STAGEDIR}${PREFIX}/share/icons/${_DIRNAME}-White
	cd ${WRKSRC}/dist/dark && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/${_DIRNAME}
	cd ${WRKSRC}/dist/light && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/${_DIRNAME}-White

.include <bsd.port.mk>

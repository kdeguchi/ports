# $FreeBSD: x11-themes/capitaine-cursors/Makefile 2526 2020-05-18 04:43:01Z  $

PORTNAME=	capitaine-cursors
PORTVERSION=	r4
CATEGORIES=	x11-themes

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Capitaine Cursors

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		inkscape:graphics/inkscape \
		xcursorgen:x11/xcursorgen

USE_GITHUB=	yes
GH_ACCOUNT=	keeferrourke
GH_TAGNAME=	f6281e8

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

PORTNAME=	web-greeter
PORTVERSION=	3.5.3
CATEGORIES=	x11
MASTER_SITES=	LOCAL:npmcahce
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Web Greeter for LightDM
WWW=		https://github.com/JezerM/web-greeterer

LICENSE=	GPLv3

CONFLICTS=	sea-greeter-*

BUILD_DEPENDS=	npm:www/npm

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml

OPTIONS_DEFINE=	DOCS

USES=		gettext gmake gnome localbase nodejs:build pkgconfig python \
		pyqt:5 qt:5 shebangfix xorg
USE_GNOME=	glib20 gtk30 pygobject3
USE_XORG=	x11 xcb
USE_PYQT=	webengine
USE_PYTHON=	flavors
USE_QT=		webengine

USE_GITHUB=	yes
GH_TUPLE=	JezerM:web-greeter:f33a7d6 \
		JezerM:web-greeter-themes:44283ca:themes/themes \
		JezerM:nody-greeter-types:4bf0196:tsc/themes/ts-types

MAKE_ENV+=	PATH=${WRKSRC}/node_modules/.bin:${PATH}
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-fPIC

bash_CMD=	/bin/sh
SHEBANG_FILES=	dist/Xgreeter \
		src/bridge/__init__.py

post-patch:
	@${REINPLACE_CMD} -e 's,$${INSTALL_ROOT}/etc,$${INSTALL_ROOT}$${PREFIX}/etc,' \
		-e 's,sed .*,grep ID= | sed "s/ID=//"),' \
		-e 's,gcc,cc ${CLAGS} ${CPPFLAGS} ${LIBS},' \
		-e 's,#!/usr/bin/env .*/lib/web-greeter,#!/bin/sh\\n${PYTHON_CMD} ${PREFIX}/lib/web-greeter,' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},;s,/etc,${PREFIX}/etc,;' \
		${WRKSRC}/dist/90-greeter-wrapper.conf \
		${WRKSRC}/dist/web-greeter.1 \
		${WRKSRC}/dist/web-greeter.yml \
		${WRKSRC}/docs/*.js \
		${WRKSRC}/src/*.py \
		${WRKSRC}/src/*/*.py \
		${WRKSRC}/themes/themes/*/js/*.js
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml \
		${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml.sample

make-npm-cache: patch
	cd ${WRKDIR} && ${RM} -r .npm
	cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} npm install typescript
	cd ${WRKDIR} && \
		${TAR} -cJf ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm
	${CP} -a ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} ${DISTDIR}

.include <bsd.port.mk>

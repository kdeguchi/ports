PORTNAME=	web-greeter
PORTVERSION=	3.5.2
CATEGORIES=	x11

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Web Greeter for LightDM
WWW=		https://github.com/JezerM/web-greeterer

LICENSE=	GPLv3

BUILD_DEPENDS=	npm:www/npm

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify

OPTIONS_DEFINE=	DOCS

USES=		gettext gmake gnome localbase pkgconfig python pyqt:5 qt:5 shebangfix xorg
USE_GNOME=	glib20 gtk30 pygobject3
USE_XORG=	x11 xcb
USE_PYQT=	webengine
USE_PYTHON=	flavors
USE_QT=	webengine

USE_GITHUB=	yes
GH_TUPLE=	JezerM:web-greeter:35e96f9 \
		JezerM:web-greeter-themes:44283ca:themes \
		JezerM:nody-greeter-types:4bf0196:tsc

MAKE_ENV+=	PATH=${WRKSRC}/node_modules/.bin:${PATH}
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-fPIC

bash_CMD=	/bin/sh
SHEBANG_FILES=	build/utils.sh dist/Xgreeter src/bridge/__init__.py

post-extract:
	cd ${WRKSRC} && \
		${RMDIR} themes && \
		${LN} -sfn ../web-greeter-themes-* themes && \
		${RMDIR} themes/ts-types && \
		${LN} -sfn ../nody-greeter-types-* themes/ts-types

post-patch:
	${REINPLACE_CMD} -e 's,$${INSTALL_ROOT}/etc,$${INSTALL_ROOT}$${PREFIX}/etc,;s,sed .*,grep ID= | sed "s/ID=//"),;s,gcc,cc ${CFLAGS} ${LIBS} ${LDFLAGS},' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,sed -i,sed -i"",;' ${WRKSRC}/build/utils.sh
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/dist/web-greeter.yml ${WRKSRC}/src/*.py ${WRKSRC}/src/*/*.py ${WRKSRC}/themes/themes/*/js/*.js
	${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,' ${WRKSRC}/dist/90-greeter-wrapper.conf

post-configure:
	cd ${WRKSRC} && npm install typescript

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml ${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml.sample

.include <bsd.port.mk>

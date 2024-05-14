PORTNAME=	sea-greeter
PORTVERSION=	0.1
CATEGORIES=	x11
MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Another LightDM greeter made with WebKitGTK2
WWW=		https://jezerm.github.io/web-greeter-page/

LICENSE=	GPLv3

CONFLICTS=	web-greeter-*

BUILD_DEPENDS=	npm:www/npm

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libyaml.so:textproc/libyaml

OPTIONS_DEFINE=	DOCS

USES=		gettext gmake gnome localbase meson nodejs pkgconfig shebangfix xorg
USE_GNOME=	glib20 gtk30
USE_XORG=	x11 xcb

USE_GITHUB=	yes
GH_TUPLE=	JezerM:sea-greeter:ffd2f3c \
		JezerM:web-greeter-themes:44283ca:themes \
		JezerM:nody-greeter-types:4bf0196:tsc

CONFIGURE_ENV+=	PATH=${WRKSRC}/node_modules/.bin:${PATH}
MAKE_ENV+=	PATH=${WRKSRC}/node_modules/.bin:${PATH}
MAKE_JOBS_UNSAFE=	yes

post-extract:
	cd ${WRKSRC} && \
		${RMDIR} themes && \
		${LN} -sfn ../web-greeter-themes-* themes && \
		${RMDIR} themes/ts-types && \
		${LN} -sfn ../nody-greeter-types-* themes/ts-types

post-patch:
	${REINPLACE_CMD} -e 's@/usr@${PREFIX}@g;s@/etc@${PREFIX}/etc@g;' \
		${WRKSRC}/data/meson.build \
		${WRKSRC}/data/sea-greeter.desktop \
		${WRKSRC}/data/web-greeter.yml \
		${WRKSRC}/src/meson.build \
		${WRKSRC}/meson.options \
		${WRKSRC}/src/settings.[ch] \
		${WRKSRC}/src/theme.c \
		${WRKSRC}/valgrind.sh

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install typescript --save-dev

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml \
		${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml.sample

.include <bsd.port.mk>

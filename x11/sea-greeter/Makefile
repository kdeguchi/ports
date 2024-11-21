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
		JezerM:web-greeter-themes:44283ca:themes/themes \
		JezerM:nody-greeter-types:4bf0196:tsc/themes/ts-types

CONFIGURE_ENV+=	PATH=${WRKDIR}/node_modules/.bin:${PATH}
MAKE_ENV+=	PATH=${WRKDIR}/node_modules/.bin:${PATH}
MAKE_JOBS_UNSAFE=	yes

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

pre-build:
	${ECHO_CMD} offline=true >> ${WRKSRC}/.npmrc
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm config set cache ${WRKDIR}/node_modules

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml \
		${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml.sample

make-npm-cache: patch
	${RM} -r ${WRKSRC}/node_modules
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm cache clean --force
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm config set cache ${WRKDIR}/node_modules
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install typescript
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --cache=${WRKDIR}/node_modules --prefer-offline typescript
	cd ${WRKDIR} && \
		${TAR} -cJf ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} -C ${WRKDIR} node_modules
	${CP} -a ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} ${DISTDIR}

.include <bsd.port.mk>

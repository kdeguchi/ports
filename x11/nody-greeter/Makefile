PORTNAME=	nody-greeter
PORTVERSION=	1.5.2
CATEGORIES=	x11

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	LightDM greeter made with Electron.js and NodeGTK
WWW=		https://github.com/JezerM/nody-greeterer

LICENSE=	GPLv3

BUILD_DEPENDS=	npm:www/npm

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

OPTIONS_DEFINE=	DOCS

USES=		gettext gmake gnome localbase nodejs:build,run pathfix pkgconfig \
		python xorg
USE_GNOME=	cairo glib20 gtk30 introspection pango
USE_XORG=	x11 xcb

USE_GITHUB=	yes
GH_TUPLE=	JezerM:nody-greeter:8455b07 \
		JezerM:web-greeter-themes:44283ca:themes \
		JezerM:nody-greeter-types:4bf0196:tsc

MAKE_JOBS_UNSAFE=	yes

post-extract:
	cd ${WRKSRC} && \
		${RMDIR} themes && \
		${LN} -sfn ../web-greeter-themes-* themes && \
		${RMDIR} themes/ts-types && \
		${LN} -sfn ../nody-greeter-types-* themes/ts-types

post-patch:
	${REINPLACE_CMD} 's@/usr@${PREFIX}@;s@/etc/lightdm@${PREFIX}/etc/lightdm@;s@/etc/xdg@${PREFIX}/etc/xdg@' \
		${WRKSRC}/*.js ${WRKSRC}/*/*.js ${WRKSRC}/*/*.ts
#	${REINPLACE_CMD} 's@16\.2\.8@23.0.0@' ${WRKSRC}/package.json

pre-configure:
	${MKDIR} ${WRKDIR}/.bin ${WRKSRC}/node_modules/.bin
	${LN} -sf /usr/local/bin/gmake ${WRKDIR}/.bin/make

post-configure:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm install

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm run rebuild && \
		${SETENV} ${MAKE_ENV} npm run build

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml \
		${STAGEDIR}${PREFIX}/etc/lightdm/web-greeter.yml.sample

.include <bsd.port.mk>

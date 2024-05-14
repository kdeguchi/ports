PORTNAME=	lightdm-webkit-theme-litarvan
PORTVERSION=	3.2.0
CATEGORIES=	x11-themes

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Litarvan's LightDM HTML Theme
WWW=		https://github.com/Litarvan/lightdm-webkit-theme-litarvan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm:www/npm
RUN_DEPENDS=	lightdm>0:x11/lightdm

USE_GITHUB=	yes
GH_ACCOUNT=	JezerM
GH_TAGNAME=	bb458b9

OPTIONS_SINGLE=	GREETER
OPTIONS_SINGLE_GREETER=	SEA_GREETER WEB_GREETER

SEA_GREETER_DESC=	WebKitGTK2 LightDM Greeter
WEB_GREETER_DESC=	Qt5WebEngine LightDM Greeter

SEA_GREETER_RUN_DEPENDS=	sea-greeter:x11/sea-greeter
WEB_GREETER_RUN_DEPENDS=	web-greeter:x11/web-greeter

NO_ARCH=	yes

do-build:
	cd ${WRKSRC} && ${RM} -rf dist && npm ci && npm run-script build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/litarvan
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/web-greeter/themes/litarvan

.include <bsd.port.mk>

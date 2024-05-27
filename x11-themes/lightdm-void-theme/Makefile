PORTNAME=	lightdm-void-theme
PORTVERSION=	0.2.0
CATEGORIES=	x11-themes
DISTVERSIONPREFIX=	v

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	LightDM theme inspired in Void Linux (without any reason)
WWW=		https://github.com/JezerM/lightdm-void-theme

BUILD_DEPENDS=	npm:www/npm
RUN_DEPENDS=	lightdm>0:x11/lightdm

OPTIONS_SINGLE=	GREETER
OPTIONS_SINGLE_GREETER=	SEA_GREETER WEB_GREETER

SEA_GREETER_DESC=	WebKitGTK2 LightDM Greeter
WEB_GREETER_DESC=	Qt5WebEngine LightDM Greeter
SEA_GREETER_RUN_DEPENDS=	sea-greeter:x11/sea-greeter
WEB_GREETER_RUN_DEPENDS=	web-greeter:x11/web-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	JezerM
GH_TAGNAME=	dcd2ccc

NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -type f \( -name '*.html' -o -name '*.yml' -o -name '*.ts' -o -name '*.vue' \) \
		-exec ${REINPLACE_CMD} -i '' -e 's@/usr/share@${PREFIX}/share@g;' {} +

do-build:
	cd ${WRKSRC} && ${RM} -rf dist && npm ci && npm run-script build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/${PORTNAME}
	cd ${WRKSRC}/dist && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/web-greeter/themes/${PORTNAME}

.include <bsd.port.mk>

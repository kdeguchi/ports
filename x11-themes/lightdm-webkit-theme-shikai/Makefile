PORTNAME=	lightdm-webkit-theme-shikai
PORTVERSION=	1.4.3
CATEGORIES=	x11-themes

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern lightdm webkit2 theme
WWW=		https://github.com/TheWisker/Shikai

LICENSE=	GPLv3

RUN_DEPENDS=	lightdm>0:x11/lightdm

#OPTIONS_DEFINE=	GREETER
OPTIONS_SINGLE=	GREETER
OPTIONS_SINGLE_GREETER=	SEA_GREETER WEB_GREETER

SEA_GREETER_DESC=	WebKitGTK2 LightDM Greeter
WEB_GREETER_DESC=	Qt5WebEngine LightDM Greeter

SEA_GREETER_RUN_DEPENDS=	sea-greeter:x11/sea-greeter
WEB_GREETER_RUN_DEPENDS=	web-greeter:x11/web-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	TheWisker
GH_PROJECT=	Shikai
GH_TAGNAME=	b034092

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} 's@window.__is_debug = true;@window.__is_debug = false;@' ${WRKSRC}/dist/*.html
	${RM} ${WRKSRC}/dist/*.bak

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/shikai
	cd ${WRKSRC}/dist/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/web-greeter/themes/shikai

.include <bsd.port.mk>

PORTNAME=	lightdm-webkit-theme-shikai
PORTVERSION=	1.3.0
CATEGORIES=	x11-themes

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern lightdm webkit2 theme
WWW=		https://github.com/TheWisker/Shikai

LICENSE=	GPLv3

RUN_DEPENDS=	lightdm>0:x11/lightdm \
		web-greeter>0:x11/web-greeter

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

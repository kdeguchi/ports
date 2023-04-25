PORTNAME=	lightdm-webkit-theme-litarvan
PORTVERSION=	3.2.0
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/Litarvan/lightdm-webkit-theme-litarvan/releases/download/v${PORTVERSION}/
DISTFILES=	lightdm-webkit-theme-litarvan-3.2.0.tar.gz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Litarvan's LightDM HTML Theme
WWW=		https://github.com/Litarvan/lightdm-webkit-theme-litarvan

LICENSE=	GPLv3

RUN_DEPENDS=	lightdm>0:x11/lightdm

OPTIONS_SINGLE=	GREETER
OPTIONS_SINGLE_GREETER=	SEA_GREETER WEB_GREETER

SEA_GREETER_DESC=	WebKitGTK2 LightDM Greeter
WEB_GREETER_DESC=	Qt5WebEngine LightDM Greeter

SEA_GREETER_RUN_DEPENDS=	sea-greeter:x11/sea-greeter
WEB_GREETER_RUN_DEPENDS=	web-greeter:x11/web-greeter

NO_ARCH=	yes
NO_BUILD=	yes

EXTRACT_AFTER_ARGS+=	-C ${WRKSRC}

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/litarvan
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/web-greeter/themes/litarvan

.include <bsd.port.mk>

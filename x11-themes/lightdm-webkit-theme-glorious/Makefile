PORTNAME=	lightdm-webkit2-theme-glorious
PORTVERSION=	2.0.5
CATEGORIES=	x11-themes
DISTVERSIONPREFIX=	v

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Sleek, modern, and glorified lightdm webkit2 theme
WWW=		https://github.com/manilarome/lightdm-webkit2-theme-glorious

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lightdm>0:x11/lightdm

OPTIONS_SINGLE=	GREETER
OPTIONS_SINGLE_GREETER=	SEA_GREETER WEB_GREETER

SEA_GREETER_DESC=	WebKitGTK2 LightDM Greeter
WEB_GREETER_DESC=	Qt5WebEngine LightDM Greeter
SEA_GREETER_RUN_DEPENDS=	sea-greeter:x11/sea-greeter
WEB_GREETER_RUN_DEPENDS=	web-greeter:x11/web-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	JezerM
GH_TAGNAME=	b8eb908

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious
	${RM} -r ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious/.github
	${RM} -r ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious/LICENSE

.include <bsd.port.mk>

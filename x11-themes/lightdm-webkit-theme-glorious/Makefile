PORTNAME=	lightdm-webkit-theme-glorious
PORTVERSION=	2.0.5
CATEGORIES=	x11-themes
DISTVERSION=	v${PORTVERSION}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Sleek, modern, and glorified lightdm webkit2 theme
WWW=		https://github.com/manilarome/lightdm-webkit2-theme-glorious

LICENSE=	GPLv3

RUN_DEPENDS=	lightdm>0:x11/lightdm \
		web-greeter>0:x11/web-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	manilarome

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious
	${RM} -r ${STAGEDIR}${PREFIX}/share/web-greeter/themes/glorious/.github

.include <bsd.port.mk>

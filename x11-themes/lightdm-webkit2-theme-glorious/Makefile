PORTNAME=	lightdm-webkit2-theme-glorious
PORTVERSION=	2.0.5
CATEGORIES=	x11-themes
DISTVERSION=	v${PORTVERSION}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Sleek, modern, and glorified lightdm webkit2 theme
WWW=		https://github.com/manilarome/lightdm-webkit2-theme-glorious

LICENSE=	GPLv3

RUN_DEPENDS=	lightdm>0:x11/lightdm \
		lightdm-webkit2-greeter>0:x11/lightdm-webkit2-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	manilarome

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/lightdm-webkit/themes/glorious
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/lightdm-webkit/themes/glorious
	${RM} -r ${STAGEDIR}${PREFIX}/share/lightdm-webkit/themes/glorious/.github

.include <bsd.port.mk>

PORTNAME=	lightdm-webkit-theme-litarvan
PORTVERSION=	3.2.0
CATEGORIES=	x11-themes
DISTVERSION=	v${PORTVERSION}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Litarvan's LightDM HTML Theme
WWW=		https://github.com/Litarvan/lightdm-webkit-theme-litarvan

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash npm:www/npm
RUN_DEPENDS=	lightdm>0:x11/lightdm \
		web-greeter>0:x11/web-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	Litarvan

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's@npm@npm --force@;' ${WRKSRC}/build.sh

do-build:
	cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} npm --force install && \
		${SETENV} HOME=${WRKDIR} ./build.sh

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/web-greeter/themes/litarvan
	cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${PKGNAME}.tar.gz ${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share/web-greeter/themes/litarvan

.include <bsd.port.mk>

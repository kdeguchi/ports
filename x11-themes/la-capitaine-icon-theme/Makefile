PORTNAME=	la-capitaine-icon-theme
PORTVERSION=	0.6.2
CATEGORIES=	x11-themes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Icon pack designed to integrate with most desktop environments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	YES
GH_ACCOUNT=	keeferrourke
GH_TAGNAME=	8370e7c

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	LIGHT-DARK
OPTIONS_SINGLE_LIGHT-DARK=	LIGHT DARK
LIGHT_DESC=	La Capitaine Light
DARK_DESC=	La Capitaine Dark
OPTIONS_DEFAULT=	LIGHT

NO_BUILD=	YES

PORTDOCS=	Credits.md README.md Thanks.md COPYING

post-extract:
.for logo in kubuntu debian-logo configure-debian debian debian-plymouth-manager archlinux gnome-debian
	${RM} ${WRKSRC}/apps/scalable/${logo}.svg
.endfor
	cd ${WRKSRC} && \
		${RM} -r .git* .product

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine && \
	${RM} -r COPYING Credits.md LICENSE README.md Thanks.md configure scripts

do-install-DARK-on:
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine/actions && ${LN} -sfn 22x22-dark 22x22
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine/devices && ${LN} -sfn scalable-dark scalable
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine/panel && ${LN} -sfn 16-dark 16
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine/panel && ${LN} -sfn 24-dark 24
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine/places && ${LN} -sfn 16x16-dark 16x16
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine/status && ${LN} -sfn scalable-dark scalable

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

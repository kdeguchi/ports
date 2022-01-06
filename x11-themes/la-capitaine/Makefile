PORTNAME=	la-capitaine
PORTVERSION=	0.6.2
CATEGORIES=	x11-themes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	La Capitaine icons

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gnome
USE_GITHUB=	yes
GH_ACCOUNT=	keeferrourke
GH_PROJECT=	${PORTNAME}-icon-theme
GH_TAGNAME=	8370e7c

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	THEME
OPTIONS_SINGLE_THEME=	DARK LIGHT
OPTIONS_DEFAULT=	LIGHT

DARK_DESC=	Dark theme
LIGHT_DESC=	Light theme

NO_BUILD=	yes

PORTDOCS=	Credits.md README.md Thanks.md COPYING

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-DARK-on:
.for i in actions devices panel places status
	cd ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}/${i} && \
		for j in `${LS} -d *-dark`; do \
			${RM} $${j%-dark} && \
			${LN} -sf $${j} $${j%-dark}; \
		done
.endfor


post-install:
	cd ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME} && \
		${RM} -r .git* .product COPYING LICENSE Credits.md README.md Thanks.md configure scripts

.include <bsd.port.mk>

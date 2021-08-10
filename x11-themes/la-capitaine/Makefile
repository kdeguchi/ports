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

NO_BUILD=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	Credits.md README.md Thanks.md COPYING

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	cd ${STAGEDIR}${PREFIX}/share/icons/${PORTNAME} && \
		${RM} -r .git* .product COPYING LICENSE Credits.md README.md Thanks.md configure

.include <bsd.port.mk>

PORTNAME=	la-capitaine
PORTVERSION=	0.6.2
PKGNAMESUFFIX=	-icons-theme
CATEGORIES=	x11-themes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Icon pack designed to integrate with most desktop environments

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	YES
GH_ACCOUNT=	keeferrourke
GH_PROJECT=	${PORTNAME}-icon-theme
GH_TAGNAME=	8370e7c

OPTIONS_DEFINE=	DOCS

NO_BUILD=	YES

PORTDOCS=	Credits.md README.md Thanks.md COPYING

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	cd ${STAGEDIR}${PREFIX}/share/icons/La-Capitaine && \
		${RM} -r .git* .product COPYING LICENSE Credits.md README.md Thanks.md configure

.include <bsd.port.mk>

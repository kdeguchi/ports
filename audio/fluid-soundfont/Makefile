PORTNAME=	fluid-soundfont
PORTVERSION=	3.1
CATEGORIES=	audio
MASTER_SITES=	GENTOO
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Fluid R3 sound fonts (GM/GS)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	share/sounds/sf2/FluidR3_GM.sf2 \
		share/sounds/sf2/FluidR3_GS.sf2 \
		share/timidity/fluidr3_gm.cfg \
		share/timidity/fluidr3_gs.cfg
PORTDOCS=	README

SUB_FILES=	fluidr3_gm.cfg fluidr3_gs.cfg
SUB_LIST=	PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/sounds/sf2
	${INSTALL_DATA} ${WRKSRC}/FluidR3_G?.sf2 \
		${STAGEDIR}${PREFIX}/share/sounds/sf2
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/timidity
	${INSTALL_DATA} ${WRKDIR}/fluidr3_g?.cfg \
		${STAGEDIR}${PREFIX}/share/timidity

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

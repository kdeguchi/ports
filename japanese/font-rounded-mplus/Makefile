PORTNAME=	rounded-mplus
PORTVERSION=	20150529
#PORTREVISION=	0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SOURCEFORGE_JP
MASTER_SITE_SUBDIR=users/8/8569
PKGNAMEPREFIX=	ja-font-

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Rounded M+ Japanese TrueType fonts

LICENSE=	OFL11

USES=		7z fonts:fc
FONTPATHSPEC=	${FONTNAME}:pri=60

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-install
NO_WRKSUBDIR=	yes

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

PORTDOCS=	*

OPTIONS_DEFINE=			DOCS
OPTIONS_DEFAULT=		ROUNDED_MPLUS_1C \
				ROUNDED_MPLUS_1M \
				ROUNDED_MPLUS_1MN \
				ROUNDED_MPLUS_1P \
				ROUNDED_MPLUS_2C \
				ROUNDED_MPLUS_2M \
				ROUNDED_MPLUS_2P
OPTIONS_MULTI=			FONT_FAMILY
OPTIONS_MULTI_FONT_FAMILY=	ROUNDED_MPLUS_1C \
				ROUNDED_MPLUS_1M \
				ROUNDED_MPLUS_1MN \
				ROUNDED_MPLUS_1P \
				ROUNDED_MPLUS_2C \
				ROUNDED_MPLUS_2M \
				ROUNDED_MPLUS_2P
OPTIONS_SUB=			yes

ROUNDED_MPLUS_1C_DESC=	Rounded M+ 1c
ROUNDED_MPLUS_1MN_DESC=	Rounded M+ 1mn
ROUNDED_MPLUS_1M_DESC=	Rounded M+ 1m
ROUNDED_MPLUS_1P_DESC=	Rounded M+ 1p
ROUNDED_MPLUS_2C_DESC=	Rounded M+ 2c
ROUNDED_MPLUS_2M_DESC=	Rounded M+ 2m
ROUNDED_MPLUS_2P_DESC=	Rounded M+ 2p

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MROUNDED_MPLUS_1C}
FAMILY=	1c
.endif
.if ${PORT_OPTIONS:MROUNDED_MPLUS_1M}
FAMILY+=1m
.endif
.if ${PORT_OPTIONS:MROUNDED_MPLUS_1MN}
FAMILY+=1mn
.endif
.if ${PORT_OPTIONS:MROUNDED_MPLUS_1P}
FAMILY+=1p
.endif
.if ${PORT_OPTIONS:MROUNDED_MPLUS_2C}
FAMILY+=2c
.endif
.if ${PORT_OPTIONS:MROUNDED_MPLUS_2M}
FAMILY+=2m
.endif
.if ${PORT_OPTIONS:MROUNDED_MPLUS_2P}
FAMILY+=2p
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for FAM in ${FAMILY}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${FAM}-*.ttf \
	    ${STAGEDIR}${FONTSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name *\.ttf"

.include <bsd.port.mk>

PORTNAME=	epson
PORTVERSION=	3.2.1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://www.epson.jp/dl_soft/file/27767/
PKGNAMEPREFIX=	ja-font-

DISTNAME=	EPSONTTF_v${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.exe

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	EPSON TrueTypeFont

LICENSE_FILE=	LA

USES=		fonts:fc

FONTPATHSPEC=	${FONTNAME}:pri=60

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-install

NO_WRKSUBDIR=	yes

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Data/*.ttf \
	    ${STAGEDIR}${FONTSDIR}
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

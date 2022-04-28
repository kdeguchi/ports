PORTNAME=	cnijfilter2
PORTVERSION=	6.30
CATEGORIES=	print
MASTER_SITES=	http://gdlp01.c-wss.com/gds/8/0100011318/01/
DISTVERSIONSUFFIX=-1-rpm
#https://gdlp01.c-wss.com/gds/8/0100011318/01/cnijfilter2-6.30-1-rpm.tar.gz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Caonon IJ Printer driver

USES=	linux
USE_LINUX=	avahi-libs cups-libs dbuslibs libxml2
USE_LINUX_PREFIX=	yes
USE_LDCONFIG=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	aarch64 amd64 i386 mips64el

OPTIONS_DEFINE=	DOCS

.if defined(ARCH) && ${ARCH:Mamd64}
_ARCH=	x86_64
.elif defined(ARCH) && ${ARCH:Mi386}
_ARCH=	i386
.elif defined(ARCH) && ${ARCH:Maarch64}
_ARCH=	aarch64
.elif defined(ARCH) && ${ARCH:Mmips64el}
_ARCH=	mips64el
.endif

post-extract:
	cd ${WRKSRC}/packages && \
		${MKDIR} ${_ARCH} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME:S/-rpm/.${_ARCH}.rpm/} -C ./${_ARCH}

do-install:
	cd ${WRKSRC}/packages/${_ARCH} && \
		${CP} -a usr ${STAGEDIR}${LINUXBASE} && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/bin && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/backend && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/share/cups/model
.for i in tocanonij tocnpwg
	${LN} -s ${LINUXBASE}${LOCALBASE}/bin/${i} ${STAGEDIR}${LOCALBASE}/bin/
.endfor
	${LN} -s ${LINUXBASE}/usr/lib/cups/backend/cnijbe2 ${STAGEDIR}${LOCALBASE}/libexec/cups/backend/
.for i in cmdtocanonij2 cmdtocanonij3 rastertocanonij
	${LN} -s ${LINUXBASE}/usr/lib/cups/filter/${i} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter/
.endfor
	for i in `ls ${STAGEDIR}${LINUXBASE}/usr/share/cups/model`; do \
		${LN} -s ${LINUXBASE}/usr/share/cups/model/$${i} ${STAGEDIR}${LOCALBASE}/share/cups/model/; \
	done

do-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/usr/share/doc

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${LOCALBASE} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}||' >> ${TMPPLIST}

.include <bsd.port.mk>

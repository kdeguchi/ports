PORTNAME=	cnijfilter2
PORTVERSION=	6.30
CATEGORIES=	print
MASTER_SITES=	http://gdlp01.c-wss.com/gds/8/0100011318/01/
DISTVERSIONSUFFIX=-1-rpm
#https://gdlp01.c-wss.com/gds/8/0100011318/01/cnijfilter2-6.30-1-rpm.tar.gz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Caonon IJ Printer driver

RUN_DEPENDS=	linux_libusb>0:devel/linux_libusb

USES=	linux
USE_LINUX=	avahi-libs cups-libs dbuslibs libxml2
USE_LINUX_PREFIX=	yes
USE_LDCONFIG=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	aarch64 amd64 i386 mips64el

OPTIONS_DEFINE=	DOCS

.if defined(ARCH) && ${ARCH:Mamd64}
_ARCH=	x86_64
.else
_ARCH=	${ARCH}
.endif

post-extract:
	cd ${WRKSRC}/packages && \
		${MKDIR} ${_ARCH} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME:S/-rpm/.${_ARCH}.rpm/} -C ./${_ARCH}

do-install:
	cd ${WRKSRC}/packages/${_ARCH} && \
		${CP} -a usr ${STAGEDIR}${PREFIX} && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/bin && \
		for i in `ls ${STAGEDIR}${PREFIX}/usr/bin`; do \
			${LN} -s ${PREFIX}/usr/bin/$${i} ${STAGEDIR}${LOCALBASE}/bin/; \
		done
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/backend && \
		for i in `ls ${STAGEDIR}${PREFIX}/usr/lib/cups/backend`; do \
			${LN} -s ${PREFIX}/usr/lib/cups/backend/$${i} ${STAGEDIR}${LOCALBASE}/libexec/cups/backend/; \
		done
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter && \
		for i in `ls ${STAGEDIR}${PREFIX}/usr/lib/cups/filter`; do \
			${LN} -s ${PREFIX}/usr/lib/cups/filter/$${i} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter/; \
		done
		${MKDIR} ${STAGEDIR}${LOCALBASE}/share/cups/model && \
		for i in `ls ${STAGEDIR}${PREFIX}/usr/share/cups/model`; do \
			${LN} -s ${PREFIX}/usr/share/cups/model/$${i} ${STAGEDIR}${LOCALBASE}/share/cups/model/; \
		done
		#${RM} ${STAGEDIR}${PREFIX}/usr/bin/cnijlgmon3 && \

do-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/usr/share/doc

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${LOCALBASE} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}||' >> ${TMPPLIST}

.include <bsd.port.mk>

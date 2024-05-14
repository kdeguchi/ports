PORTNAME=	cnijfilter2
PORTVERSION=	6.30
DISTVERSIONSUFFIX=-1-rpm
CATEGORIES=	print
MASTER_SITES=	http://gdlp01.c-wss.com/gds/8/0100011318/01/
#https://gdlp01.c-wss.com/gds/8/0100011318/01/cnijfilter2-6.30-1-rpm.tar.gz
PKGNAMEPREFIX=	linux-c7-

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Caonon IJ Printer driver
WWW=		https://cweb.canon.jp/drv-upd/ij-mfp/linux-pd-20211h-630.html

ONLY_FOR_ARCHS=	aarch64 amd64 i386 mips64el

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

USES=	linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	avahi-libs cups-libs dbuslibs libxml2
USE_LINUX_PREFIX=	yes

.if defined(ARCH) && ${ARCH:Mamd64}
_ARCH=	x86_64
_LIBDIR=	${STAGEDIR}${PREFIX}/usr/lib64
.else
_ARCH=	${ARCH}
.endif

#LICENSE=	CANON
#LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
#LICENSE_NAME=	Canon Inc.
#LICENSE_FILE=	${WRKSRC}/documents/LICENSE-cnijfilter-6.30EN.txt
#LICENSE_DISTFILES=	${DISTFILES}

post-extract:
	cd ${WRKSRC}/packages && \
		${MKDIR} ${_ARCH} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${DISTNAME:S/-rpm/.${_ARCH}.rpm/} -C ./${_ARCH}

do-install:
	cd ${WRKSRC}/packages/${_ARCH} && \
		${CP} -a usr ${STAGEDIR}${PREFIX} && \
		${RM} ${STAGEDIR}${PREFIX}/usr/bin/cnijlgmon3 && \
		${RM} -r ${STAGEDIR}${PREFIX}/usr/share/locale && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/bin && \
		for i in ${STAGEDIR}${PREFIX}/usr/bin/*; do \
			i=`basename $${i}` && \
			${RLN} ${STAGEDIR}${PREFIX}/usr/bin/$${i} ${STAGEDIR}${LOCALBASE}/bin/$${i}; \
		done
.if defined(_ARCH) && ${_ARCH:Mx86_64}
		${MV} ${STAGEDIR}${PREFIX}/usr/lib/* ${_LIBDIR} && \
		${RMDIR} ${STAGEDIR}${PREFIX}/usr/lib
.endif
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/backend && \
		for i in ${_LIBDIR}/cups/backend/*; do \
			i=`basename $${i}` && \
			${RLN} ${_LIBDIR}/cups/backend/$${i} \
				${STAGEDIR}${LOCALBASE}/libexec/cups/backend/$${i}; \
		done
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter && \
		for i in ${_LIBDIR}/cups/filter/*; do \
			i=`basename $${i}` && \
			${RLN} ${_LIBDIR}/cups/filter/$${i} \
				${STAGEDIR}${LOCALBASE}/libexec/cups/filter/$${i}; \
		done
		${MKDIR} ${STAGEDIR}${LOCALBASE}/share/cups/model && \
		for i in ${STAGEDIR}${PREFIX}/usr/share/cups/model/*; do \
			i=`basename $${i}` && \
			${RLN} ${STAGEDIR}${PREFIX}/usr/share/cups/model/$${i} \
				${STAGEDIR}${LOCALBASE}/share/cups/model/$${i}; \
		done

do-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/usr/share/doc

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${LOCALBASE} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}||' >> ${TMPPLIST}

.include <bsd.port.mk>

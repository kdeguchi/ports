PORTNAME=	man
PORTVERSION=	${OSREL}.20210525
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.koganemaru.co.jp/pub/jman${OSREL:C@\.[0-9]+@@}/
PKGNAMESUFFIX=	-doc
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.${ARCH}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Japanese translation of FreeBSD manual pages

USES=		iconv tar:txz

EXTRACT_BEFORE_ARGS=	-pxf
EXTRACT_AFTER_ARGS=	-C ${WRKSRC} \
		--exclude +COMPACT_MANIFEST \
		--exclude +MANIFEST \
		--exclude +MTREE_DIRS \
		-s '|/usr|${PREFIX}|gs'

#DISTINFO_FILE=	${.CURDIR}/distinfo.${ARCH}
PLIST=	${.CURDIR}/pkg-plist

SUB_FILES=	eucjp2utf8.sh
SUB_LIST=	AWK="${AWK}" CUT="${CUT}" ECHO_CMD="${ECHO_CMD}" FIND="${FIND}" \
		GZCAT="${GZCAT}" GZIP_CMD="${GZIP_CMD}" ICONV_CMD="${ICONV_CMD}" \
		LN="${LN}" SORT="${SORT}"

NO_BUILD=	yes

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${TAR} -cf - -C ${WRKSRC}${DATADIR} . | ${TAR} -xpf - -C ${STAGEDIR}${MANPREFIX}/share/man
	${SH} ${WRKDIR}/eucjp2utf8.sh ${STAGEDIR}${MANPREFIX}/share/man
	cd ${STAGEDIR}${MANPREFIX}/share/man && \
		${LN} -s ja ja_JP.UTF-8 && \
		${LN} -s ja ja.UTF-8

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

compress-man:

.include <bsd.port.mk>

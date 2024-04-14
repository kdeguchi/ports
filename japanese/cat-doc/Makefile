PORTNAME=	cat
PORTVERSION=	${OSREL}.20231110
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.koganemaru.co.jp/pub/jman${OSREL:C@\.[0-9]+@@}/
PKGNAMESUFFIX=	-doc
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Japanese translation of FreeBSD cat manual pages

LICENSE=	BSD

USES=	iconv tar:txz

EXTRACT_BEFORE_ARGS=	-pxf
EXTRACT_AFTER_ARGS=	-C ${WRKSRC} \
		--exclude +COMPACT_MANIFEST \
		--exclude +MANIFEST \
		--exclude +MTREE_DIRS \
		-s '|/usr|${PREFIX}|gs'

NO_BUILD=	yes

SUB_FILES=	eucjp2utf8.sh
SUB_LIST=	AWK="${AWK}" CUT="${CUT}" ECHO_CMD="${ECHO_CMD}" FIND="${FIND}" \
		GZCAT="${GZCAT}" GZIP_CMD="${GZIP_CMD}" ICONV_CMD="${ICONV_CMD}" \
		LN="${LN}" SORT="${SORT}"

.include <bsd.port.pre.mk>

.if defined(ARCH) && ${ARCH} == "amd64"
DISTNAME:=	${DISTNAME}.${ARCH}
DISTINFO_FILE=	${MASTERDIR}/distinfo.${ARCH}
.endif

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	cd ${STAGEDIR}${PREFIX}/share/man && \
		${LN} -s ja ja.UTF-8 && ${LN} -s ja ja_JP.UTF-8
	${TAR} -cf - -C ${WRKSRC}${PREFIX}/share/man . | ${TAR} -xpf - -C ${STAGEDIR}${PREFIX}/share/man
	${SH} ${WRKDIR}/eucjp2utf8.sh ${STAGEDIR}${PREFIX}/share/man

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

compress-man:

.include <bsd.port.post.mk>

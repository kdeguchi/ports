# $FreeBSD: japanese/cat-doc/Makefile 680 2014-03-12 20:57:16Z  $

PORTNAME=	cat
PORTVERSION=	13.0.20200925
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.koganemaru.co.jp/pub/jmanc/
PKGNAMESUFFIX=	-doc
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
EXTRACT_SUFX=	.txz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Japanese translation of FreeBSD cat manual pages

USES=	iconv tar:xz

EXTRACT_BEFORE_ARGS=	-pxf
EXTRACT_AFTER_ARGS=	-C ${WRKSRC} \
		--exclude +COMPACT_MANIFEST \
		--exclude +MANIFEST \
		--exclude +MTREE_DIRS \
		-s '|/usr|${PREFIX}|gs'

SUB_FILES=	eucjp2utf8.sh
SUB_LIST=	AWK="${AWK}" CUT="${CUT}" ECHO_CMD="${ECHO_CMD}" FIND="${FIND}" \
		GZCAT="${GZCAT}" GZIP_CMD="${GZIP_CMD}" ICONV_CMD="${ICONV_CMD}" \
		LN="${LN}" SORT="${SORT}"

NO_BUILD=	yes

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${TAR} -cf - -C ${WRKSRC}${MANPREFIX}/share/man . | ${TAR} -xpf - -C ${STAGEDIR}${MANPREFIX}/share/man
	${SH} ${WRKDIR}/eucjp2utf8.sh ${STAGEDIR}${MANPREFIX}/share/man
	cd ${STAGEDIR}${MANPREFIX}/share/man && \
		${LN} -s ja ja_JP.UTF-8 && \
		${LN} -s ja ja.UTF-8

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

compress-man:

.include <bsd.port.mk>

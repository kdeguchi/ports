# $FreeBSD: japanese/cat-doc/Makefile 680 2014-03-12 20:57:16Z  $

PORTNAME=	cat
PORTVERSION=	${OSREL}.20181125
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.koganemaru.co.jp/pub/jmanc/
PKGNAMESUFFIX=	-doc
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
EXTRACT_SUFX=	.txz
EXTRACT_ONLY=	${DISTFILES}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Japanese translation of FreeBSD cat manual pages

EXTRACT_BEFORE_ARGS=	-pxf
USES=	tar:xz
NO_BUILD=	yes

MANPREFIX=	${PREFIX}/share

do-install:
	cd ${WRKDIR}/usr/share/man/ja && \
	${TAR} -cf - . | ${TAR} -xpf - -C ${STAGEDIR}${MANPREFIX}/man/ja
	cd ${STAGEDIR}${MANPREFIX} && \
		${LN} -s ja ja_JP.UTF-8 && \
		${LN} -s ja ja.UTF-8

compress-man:

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.mk>

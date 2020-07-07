# $FreeBSD: mail/targrey/Makefile 482 2013-11-05 07:51:15Z  $

PKGNAMEPREFIX=	targrey-0.31-

#PATCH_SITES=	http://k2net.hakuba.jp/pub/
#PATCHFILES=	${PKGNAMEPREFIX}postgrey-1.34.patch
#PATCH_DIST_STRIP=-p1

COMMENT=	S25R + tarpitting + greylisting policy server for Postfix

CONFLICTS=	postgrey-[0-9]*

DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
MASTERDIR=	${.CURDIR}/../../mail/postgrey

.include "${MASTERDIR}/Makefile"

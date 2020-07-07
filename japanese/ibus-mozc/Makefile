# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD: japanese/ibus-mozc/Makefile 2487 2020-05-04 00:16:42Z  $

PKGNAMEPREFIX=	ja-ibus-

COMMENT=	Mozc engine for IBus

DATADIR=	${PREFIX}/share/ibus-${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
FILESDIR=	${.CURDIR}/files
SUB_FILES=	pkg-message

BUILD_MOZC_LIST=	ibus_mozc

.include "${MASTERDIR}/Makefile"

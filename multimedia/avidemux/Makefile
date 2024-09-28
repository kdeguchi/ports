# assuming freebsd always has 16 byte aligned malloc as macos does. is this true?
# nls files not getting installed with nls=on. are they getting built?
# sync port options with current software options

PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor
WWW=		https://avidemux.org/

.include "${.CURDIR}/Makefile.common"

AVCODEC_VERSION=	61
AVFORMAT_VERSION=	61
AVUTIL_VERSION=		59
POSTPROC_VERSION=	58
SWSCALE_VERSION=	8

PLIST_SUB+=	AVCODEC_VERSION=${AVCODEC_VERSION} \
		AVFORMAT_VERSION=${AVFORMAT_VERSION} \
		AVUTIL_VERSION=${AVUTIL_VERSION} \
		POSTPROC_VERSION=${POSTPROC_VERSION} \
		SWSCALE_VERSION=${SWSCALE_VERSION}

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_core

post-configure: post-configure-common

post-install:
.for l in
avcodec.so.${AVCODEC_VERSION} avformat.so.${AVFORMAT_VERSION} avutil.so.${AVUTIL_VERSION} postproc.so.${POSTPROC_VERSION} swscale.so.${SWSCALE_VERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libADM6${l}
.endfor

.include <bsd.port.post.mk>

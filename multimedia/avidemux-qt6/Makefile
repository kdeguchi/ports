PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-qt6

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (QT6 UI)

LIB_DEPENDS=	libADM6avutil.so.${AVUTIL_VERSION}:multimedia/avidemux

MASTERDIR=	${.CURDIR}/../avidemux
OPTIONS_SLAVE=	QT6
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

USES+=	desktop-file-utils

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux/qt4

CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}"

post-configure: post-configure-common

.include <bsd.port.post.mk>

# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: head/x11-toolkits/libXt/Makefile 476013 2018-07-31 18:41:30Z zeising $

PORTNAME=	libXt
PORTVERSION=	1.2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe xorg xorg-cat:lib
USE_XORG=	x11 sm ice xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxt

CONFIGURE_ARGS=	--disable-specs

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure

.include <bsd.port.mk>

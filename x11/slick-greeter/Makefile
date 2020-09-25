# Created by: Eric Turgeon <ericbsd@FreeBSD.org>
# $FreeBSD: x11/slick-greeter/Makefile 2532 2020-05-23 04:54:08Z  $

PORTNAME=	slick-greeter
PORTVERSION=	1.4.1
#PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Slick-looking LightDM greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libcanberra-gtk3.so:audio/libcanberra-gtk3
BUILD_DEPENDS=	valac:lang/vala

USES=		autoreconf gettext gmake gnome localbase pkgconfig python \
		shebangfix xorg

USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_PYTHON=	flavors
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	x.dm.slick-greeter.gschema.xml

SHEBANG_FILES=	files/usr/bin/*

post-patch:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} -E \
			's@"/etc@"%%PREFIX%%/etc@g;s@"/usr@"%%PREFIX%%@g;s@%%PREFIX%%@${PREFIX}@g' \
			files/usr/bin/* src/*.vala && \
		${MKDIR} files${PREFIX} && \
		${MV} files/usr/bin files/usr/share files${PREFIX}

.include <bsd.port.mk>

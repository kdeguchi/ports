# Created by: Eric Turgeon <ericbsd@FreeBSD.org>

PORTNAME=	slick-greeter
PORTVERSION=	1.5.3
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Slick-looking LightDM greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	valac:lang/vala

USES=		autoreconf gettext gmake gnome localbase pkgconfig python \
		shebangfix xorg

USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_PYTHON=	flavors
USE_XORG=	pixman x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	x.dm.slick-greeter.gschema.xml

SHEBANG_FILES=	files/usr/bin/*

post-patch:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} -E \
			's@/usr/local@/usr@g;s@/etc@%%PREFIX%%/etc@g;s@/usr@%%PREFIX%%@g;s@%%PREFIX%%@${PREFIX}@g;' \
			files/usr/bin/* src/*.vala data/${PORTNAME}.8 && \
		${REINPLACE_CMD} -E 's@Gdk\.Display@Gdk.Monitor@;' files/usr/bin/* && \
		${REINPLACE_CMD} -E 's@type="d"@type="i"@' data/${GLIB_SCHEMAS} && \
		${MKDIR} files${PREFIX} && \
		${MV} files/usr/bin files/usr/share files${PREFIX}

.include <bsd.port.mk>

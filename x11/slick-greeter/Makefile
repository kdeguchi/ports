# Created by: Ben Woods <woodsb02@FreeBSD.org>

PORTNAME=	slick-greeter
PORTVERSION=	1.5.4
CATEGORIES=	x11

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Slick-looking LightDM greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		liblightdm-gobject-1.so:x11/lightdm
RUN_DEPENDS=	numlockx>=0:x11/numlockx

USES=		autoreconf gettext gmake gnome pkgconfig python:run shebangfix xorg
USE_GNOME=	cairo dconf gdkpixbuf2 gtk30 intltool pygobject3

USE_XORG=	pixman x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-deinstall pkg-install
SHEBANG_FILES=	files/usr/bin/slick-greeter-check-hidpi \
		files/usr/bin/slick-greeter-set-keyboard-layout \
		makepot
bash_OLD_CMD=	/usr/bin/bash
bash_CMD=	/bin/sh

GLIB_SCHEMAS=	x.dm.slick-greeter.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr|"${PREFIX}|g;s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/files/usr/bin/slick-greeter-set-keyboard-layout \
		${WRKSRC}/data/*.8 \
		${WRKSRC}/src/*.vala
	@${MV} ${WRKSRC}/files/usr ${WRKSRC}/files/stage
	@${MKDIR} ${WRKSRC}/files/${PREFIX}
	@${MV} ${WRKSRC}/files/stage/* ${WRKSRC}/files/${PREFIX}/
	@${RMDIR} ${WRKSRC}/files/stage

.include <bsd.port.mk>

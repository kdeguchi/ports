# Created by: Matt Lancereau <matt@rimasec.net>

PORTNAME=	orage
PORTVERSION=	4.16.0
CATEGORIES=	deskutils xfce

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Calendar application for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdt-autogen:devel/xfce4-dev-tools

LIB_DEPENDS=	libpopt.so:devel/popt \
		libdbus-1.so:devel/dbus \
		libical.so:devel/libical \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf:build compiler:c++11-lang desktop-file-utils gettext gmake gnome \
		libtool pkgconfig tar:bzip2 xfce xorg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.xfce.org
GL_ACCOUNT=	apps
GL_COMMIT=	1ddb535ab237c90a6c7ed05ed35f680ed67b8190
USE_GNOME=	cairo gtk30 intltool
USE_XFCE=	libmenu panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include/libical
CONFIGURE_ARGS=	--enable-dbus

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify

pre-patch:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=1 ./autogen.sh

post-patch-NLS-off:
	cd ${WRKSRC} && ${REINPLACE_CMD} 's@USE_NLS=yes@USE_NLS=no@' ./configure

.include <bsd.port.mk>

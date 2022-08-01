PORTNAME=	gnome-mplayer
PORTVERSION=	1.0.9
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/
DISTVERSIONSUFFIX=	.orig
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for MPlayer

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmtk.so:multimedia/gmtk
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		desktop-file-utils gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo glib20
GLIB_SCHEMAS=	apps.gecko-mediaplayer.preferences.gschema.xml \
		apps.gnome-mplayer.preferences.enums.xml \
		apps.gnome-mplayer.preferences.gschema.xml
USE_XORG=	x11 xscrnsaver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nautilus \
		--disable-nemo \
		--disable-schemas-install \
		--without-libgda \
		--without-libmusicbrainz3
WRKSRC=		${WRKDIR}/gnome-mplayer-${PORTVERSION}

OPTIONS_DEFINE=	ALSA DOCS GIO GPOD GTK3 NLS NOTIFY PULSEAUDIO

GPOD_DESC=	Add support for libgpod

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>0:audio/alsa-plugins
ALSA_CONFIGURE_WITH=	alsa

GIO_CONFIGURE_WITH=	gio
GPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod
GPOD_CONFIGURE_WITH=	libgpod

GTK3_USE=		GNOME=gtk30
GTK3_USE_OFF=		GNOME=gtk20
GTK3_CONFIGURE_ENABLE=	gtk3

NLS_USE=	gettext
NLS_LDFLAGS=	-lintl

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_RUN_DEPENDS=	notification-daemon>0:deskutils/notification-daemon
NOTIFY_CONFIGURE_WITH=	libnotify

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -E -e 's/(USE_NLS=)yes/\1no/' ${WRKSRC}/configure

post-patch:
	@${REINPLACE_CMD} -e \
		'/COPYING\\/d ; \
		 /INSTALL\\/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

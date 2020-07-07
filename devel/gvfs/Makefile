# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD: head/devel/gvfs/Makefile 410106 2016-03-04 12:26:28Z kwm $

PORTNAME=	gvfs
PORTVERSION=	1.30.4
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup \
		libgcrypt.so:security/libgcrypt \
		libgcr-base-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libgpg-error.so:security/libgpg-error \
		libcdio.so:sysutils/libcdio \
		libjson-glib-1.0.so:devel/json-glib
PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libarchive libtool localbase \
		pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack libxslt:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-bluray \
		--disable-libsystemd-login \
		--disable-gdu \
		--disable-udev \
		--disable-goa \
		--disable-libmtp \
		--disable-gtk \
		--disable-libsystemd-login \
		--disable-admin

#		--disable-gudev \
#		--disable-udisks2 \

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AFC AVAHI BASH CDDA FUSE GOOGLE \
		GPHOTO2 GUDEV HAL SMB UDISKS2
OPTIONS_DEFAULT=AVAHI CDDA FUSE GOOGLE GPHOTO2 HAL SMB UDISKS2
OPTIONS_SUB=	yes

AFC_DESC=	Apple device support
CDDA_DESC=	CDDA (enables HAL)
GOOGLE_DESC=	Google backend
GPHOTO2_DESC=	Gphoto 2 camera support (enables HAL) for PTP support
GUDEV_DESC=	gudev support
UDISKS2_DESC=	udisks2 support

AFC_LIB_DEPENDS=	libimobiledevice.so:comms/libimobiledevice \
			libplist.so:devel/libplist
AFC_CONFIGURE_ENABLE=	afc

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_VARS=	GLIB_SCHEMAS+=org.gnome.system.dns_sd.gschema.xml

BASH_CONFIGURE_OFF=	--disable-bash-completion

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CDDA_CONFIGURE_ENABLE=	cdda
CDDA_IMPLIES=	HAL

FUSE_USES=	fuse
FUSE_CONFIGURE_ENABLE=	fuse

GOOGLE_CONFIGURE_ENABLE=	google
GOOGLE_LIB_DEPENDS=	libgdata.so:devel/libgdata \
			libgoa-1.0.so:net/gnome-online-accounts

GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_CONFIGURE_ENABLE=	gphoto2
GPHOTO2_IMPLIES=	HAL

GUDEV_LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev
GUDEV_CONFIGURE_ENABLE=	gudev

HAL_LIB_DEPENDS=	libhal.so:sysutils/hal
HAL_RUN_DEPENDS=	gnome-mount:sysutils/gnome-mount
HAL_CONFIGURE_OFF=	--disable-hal

SMB_USES=	samba:lib
SMB_CONFIGURE_ENABLE=	samba
SMB_CONFIGURE_WITH=	samba-includes=${SAMBAINCLUDES} samba-libs=${SAMBALIBS}
SMB_VARS=	GLIB_SCHEMAS+=org.gnome.system.smb.gschema.xml

UDISKS2_LIB_DEPENDS=	libudisks2.so:sysutils/libudisks
UDISKS2_CONFIGURE_ENABLE=	udisks2
UDISKS2_IMPLIES=	GUDEV

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/remote-volume-monitors
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>

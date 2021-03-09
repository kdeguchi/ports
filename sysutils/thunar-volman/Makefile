# $FreeBSD: sysutils/thunar-volman/Makefile 2418 2020-03-11 08:13:08Z  $

PORTNAME=	thunar-volman
DISTVERSION=	4.16.0
CATEGORIES=	sysutils x11-fm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Volume Manager for the Thunar File Manager

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

USES=		gettext-tools gmake gnome \
		libtool localbase pathfix pkgconfig tar:bzip2 xfce
USE_GNOME=	glib20 gtk30 intltool pango
USE_XFCE=	libexo libutil thunar xfconf

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS NOTIFY
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notifications

.include <bsd.port.mk>

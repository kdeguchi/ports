# Created by: James Earl <jdearl@telus.net>
# $FreeBSD: head/x11-wm/xfce4-panel/Makefile 522690 2020-01-11 15:39:37Z madpilot $

PORTNAME=	xfce4-panel
PORTVERSION=	4.14.4
PORTREVISION=	1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's panel

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		libtool pathfix perl5 pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool libwnck3
USE_LDCONFIG=	yes
USE_XFCE=	garcon libexo xfconf
USE_XORG=	ice sm x11 xext

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-gio-unix --without-html-dir

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		COMPIZ GIR GTK2 NLS VAPI
OPTIONS_DEFAULT=	GIR GTK2 VAPI
OPTIONS_SUB=		yes

COMPIZ_DESC=	Xfce4 panel with fixes for Compiz
GIR_DESC=		Use Gobject Introspection

COMPIZ_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-plugins_pager_pager.c \
		${PATCHDIR}/extra-patch-plugins_tasklist_tasklist-widget.c

GIR_USE=		gnome=introspection:build
GIR_CONFIGURE_ON=       --enable-introspection=yes
GIR_CONFIGURE_OFF=      --enable-introspection=no

GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_ENABLE=	gtk2

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

VAPI_BUILD_DEPENDS=	vapigen:lang/vala
VAPI_CONFIGURE_ENABLE=	vala
VAPI_IMPLIES=		GIR

.include <bsd.port.mk>

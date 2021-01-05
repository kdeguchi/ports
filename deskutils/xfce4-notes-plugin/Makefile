# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD: head/deskutils/xfce4-notes-plugin/Makefile 512378 2019-09-19 23:46:33Z madpilot $

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	1.9.0
CATEGORIES=	deskutils xfce

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Notes plugin for the Xfce panel

LICENSE=	GPLv2

BUILD_DEPENDS=	xdt-autogen:devel/xfce4-dev-tools \
		valac:lang/vala
LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf:build compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo glib20 gtk30 intltool
USE_XFCE=	panel
USE_XORG=	ice sm x11

USE_GITHUB=	yes
GH_ACCOUNT=	xfce-mirror
GH_TAGNAME=	3fb993e

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh ${CONFIGURE_ARGS}

post-install-NLS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/share/locale

.include <bsd.port.mk>

# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD: head/multimedia/audacious/Makefile 541716 2020-07-08 20:05:07Z madpilot $

PORTNAME=	audacious
PORTVERSION=	4.0.4
CATEGORIES=	multimedia audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Lightweight and versatile audio player

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

FLAVORS=	qt5 gtk2
FLAVOR?=	${FLAVORS:[1]}

USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake \
		iconv localbase pkgconfig tar:bzip2 xorg
USE_XORG=	x11 sm
USE_LDCONFIG=	yes

qt5_CONFLICTS_INSTALL=	audacious-gtk2

gtk2_PKGNAMESUFFIX=	-gtk2
gtk2_CONFLICTS_INSTALL=	audacious

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--without-buildstamp

.if ${FLAVOR} == qt5
CONFIGURE_ARGS+=	--enable-qt --disable-gtk
USES+=			qt:5
USE_QT=			buildtools_build core gui widgets
PLIST_SUB=		QT5="" GTK2="@comment "
.elif ${FLAVOR} == gtk2
CONFIGURE_ARGS+=	--disable-qt --enable-gtk
USES+=			gnome
USE_GNOME=		gtk20 glib20 cairo
PLIST_SUB=		QT5="@comment " GTK2=""
.endif

OPTIONS_DEFINE=	NLS EXECINFO THUNAR
OPTIONS_DEFAULT=EXECINFO
OPTIONS_SUB=	yes
EXECINFO_DESC=	Build with libexecinfo support
THUNAR_DESC=	Build with thunar support

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch-NLS-off:
	${REINPLACE_CMD} -e 's,po,,' ${WRKSRC}/Makefile

post-patch-EXECINFO-on:
	@${REINPLACE_CMD} 's|-lm |-lm -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -lexecinfo|' \
		${WRKSRC}/audacious.pc.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aud*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*

post-install-THUNAR-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Thunar/sendto
	${INSTALL_DATA} ${WRKSRC}/contrib/thunar-sendto-audacious-playlist.desktop \
		${STAGEDIR}${PREFIX}/share/Thunar/sendto

.include <bsd.port.mk>

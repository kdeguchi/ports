# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD: multimedia/audacious/Makefile 2220 2019-12-12 23:32:28Z  $

PORTNAME=	audacious
PORTVERSION=	3.10.1
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight and versatile audio player

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake \
		gnome localbase pkgconfig tar:bzip2 xorg
USE_XORG=	x11 sm
USE_GNOME=	gtk20 glib20 cairo
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
SUB_FILES=	pkg-message

CONFLICTS_INSTALL=	audacious-gtk3-3.*

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-gtk \
		--without-buildstamp

OPTIONS_DEFINE=	EXECINFO ICONV NLS QT5 THUNAR
OPTIONS_DEFAULT=EXECINFO ICONV
OPTIONS_SUB=	yes
EXECINFO_DESC=	Build with libexecinfo support
THUNAR_DESC=	Build with thunar support

ICONV_USES=	iconv

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

QT5_CONFIGURE_ENABLE=	qt
QT5_USES=	qt:5
QT5_USE=	qt=qmake_build,buildtools_build,core,gui,widgets

post-patch:
	@${REINPLACE_CMD} -e 's| $${MFLAGS}||g' \
		${WRKSRC}/buildsys.mk.in

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

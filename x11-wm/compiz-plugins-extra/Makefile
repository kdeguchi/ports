PORTNAME=	compiz-plugins-extra
PORTVERSION=	0.8.18
PORTREVISION=	4
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libstartup-notification-1.so:x11/startup-notification

RUN_DEPENDS=	compiz:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

USES=		autoreconf gl gmake gnome libtool localbase pathfix pkgconfig xorg

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	3441d027884b37194ca821b8e689d5d569058960

USE_GL=		glu
USE_GNOME=	gdkpixbuf2 intltool libxml2 pango
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xi xinerama xorgproto xrandr xrender

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/group/group-internal.h

.include <bsd.port.mk>

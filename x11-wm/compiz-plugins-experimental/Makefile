PORTNAME=	compiz-plugins-experimental
PORTVERSION=	0.8.18
PORTREVISION=	3
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
		libcurl.so:ftp/curl \
		libstartup-notification-1.so:x11/startup-notification

RUN_DEPENDS=	compiz:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

USES=		autoreconf gl gmake gnome libtool localbase pathfix pkgconfig xorg

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	35ce86af9de1c9547bb1280f809015052d7f5713

USE_GL=		gl glew glu
USE_GNOME=	intltool
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr \
		xscrnsaver xcursor xi

HAS_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

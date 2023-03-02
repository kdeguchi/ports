PORTNAME=	compiz-plugins-experimental
PORTVERSION=	0.8.18
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcurl.so:ftp/curl \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

RUN_DEPENDS=	compiz:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gl gmake gnome libtool localbase pathfix pkgconfig xorg
USE_GL=		gl glew glu
USE_GNOME=	intltool
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr \
		xscrnsaver xcursor xi
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	61a853e848f76b73eb9b7e1c320abda8a2bafb82
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	61a853e

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

.include <bsd.port.mk>

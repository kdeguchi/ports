PORTNAME=	compiz-plugins-main
PORTVERSION=	0.8.18
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libatspi.so:accessibility/at-spi2-core \
		libcairo.so:graphics/cairo \
		libdbus-1.so:devel/dbus \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop
RUN_DEPENDS=	compiz:x11-wm/compiz

USES=		autoreconf gl gmake gnome jpeg libtool localbase pathfix pkgconfig xorg
USE_GL=	glu
USE_GNOME=	intltool
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xorgproto xrandr xrender
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	031da1bb152507c2c2b9c7a4c35d69eab4985727
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	031da1b

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

do-configure:
	cd ${WRKSRC} && ${SH} autogen.sh ${CONFIGURE_ARGS}

.include <bsd.port.mk>

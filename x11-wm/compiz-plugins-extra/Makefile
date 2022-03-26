PORTNAME=	compiz-plugins-extra
PORTVERSION=	0.8.18
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Plugins for Compiz Composite Window Manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libstartup-notification-1.so:x11/startup-notification
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:devel/compiz-bcop \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

RUN_DEPENDS=	compiz:x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/compiz-text.pc:x11-wm/compiz-plugins-main

USES=		autoreconf gl gmake gnome libtool localbase pathfix pkgconfig xorg
USE_GL=		glu
USE_GNOME=	gdkpixbuf2 intltool libxml2 pango
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xi xinerama xorgproto xrandr xrender
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	2848f4aad225c4891e8fac6e75876b1118892e6e
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	2848f4a

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/group/group-internal.h
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkg_config|' \
		${WRKSRC}/Makefile.am

do-configure:
	cd ${WRKSRC} && ${SH} autogen.sh ${CONFIGURE_ARGS}

.include <bsd.port.mk>

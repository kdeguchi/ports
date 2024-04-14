PORTNAME=	emerald
PORTVERSION=	0.8.18
PORTREVISION=	4
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Emerald Window Decorator
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=	autoreconf desktop-file-utils gl gmake gnome libtool localbase \
		pathfix pkgconfig shared-mime-info xorg

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	826408b829d57b35480e3f53573cf1f1180a4779

USE_GL=		gl
USE_GNOME=	cairo gtk30 intltool libwnck3 pango
USE_LDCONFIG=	yes
USE_XORG=	x11 xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.am
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h
	@${REINPLACE_CMD} '/^emerald_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's| -ldl||' ${WRKSRC}/configure.ac

.include <bsd.port.mk>

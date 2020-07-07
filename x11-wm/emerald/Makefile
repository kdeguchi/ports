# $FreeBSD: x11-wm/emerald/Makefile 827 2014-06-04 01:12:55Z  $

PORTNAME=	emerald
PORTVERSION=	0.8.18
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Emerald Window Decorator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS:=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
HAS_CONFIGURE=	yes
USES=	autoreconf desktop-file-utils gl gmake gnome libtool localbase \
		pathfix pkgconfig shared-mime-info xorg
USE_GL=		gl
USE_GNOME=	cairo gtk30 intltool libwnck3 pango
USE_XORG=	x11 xrender
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	6722c6ca062c55b8d70e0fadb2f687f2df19948e
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	6722c6c

INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-dependency-tracking

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.am
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h
	@${REINPLACE_CMD} '/^emerald_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's| -ldl||' ${WRKSRC}/configure.ac

do-configure:
	cd ${WRKSRC} && ${SH} autogen.sh ${CONFIGURE_ARGS}

.include <bsd.port.mk>

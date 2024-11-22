PORTNAME=	compiz
PORTVERSION=	0.8.18
PORTREVISION=	7
CATEGORIES=	x11-wm

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Compiz Composite/Window Manager
WWW=		https://github.com/compiz-reloaded

LICENSE=		GPLv2+ LGPL21+ MIT
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.MIT

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	glxinfo:graphics/mesa-demos \
		xdpyinfo:x11/xdpyinfo \
		${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_amd64=	nvidia-settings:x11/nvidia-settings
RUN_DEPENDS_i386=	nvidia-settings:x11/nvidia-settings

USES=		autoreconf gl gmake gnome iconv libtool localbase pathfix \
		pkgconfig shebangfix xorg

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_PROJECT=	compiz-core
GL_COMMIT=	155c201ec62c289c5a44b6dd23eddec3e3c20e26

USE_GL=		gl glu

USE_GNOME=	cairo glib20 intltool libxslt:build
GLIB_SCHEMAS=	org.compiz-0.gwd.gschema.xml

USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama \
		xorgproto xrandr xrender xcursor

SHEBANG_FILES=	plugins/compiz-decorator
bash_CMD=	/bin/sh

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-menu-entries --disable-dependency-tracking

INSTALL_TARGET=	install-strip

DESKTOP_ENTRIES=	"Compiz Manager" \
			"Wrapper script for starting compiz" \
			"${DATADIR}/compiz-manager.png" \
			"compiz-manager" \
			"System;Core;" \
			false

SUB_FILES=		compiz-manager

OPTIONS_DEFINE=	DBUS FUSE INOTIFY MATE NLS SVG
OPTIONS_DEFAULT=	DBUS GTK3 NLS SVG
OPTIONS_RADIO=	GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_SUB=	yes

INOTIFY_DESC=	inotify plugin support

DBUS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
DBUS_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus dbus-glib

FUSE_USES=		fuse
FUSE_CONFIGURE_ENABLE=	fuse

GTK2_IMPLIES=	DBUS
GTK2_USE=	GNOME=glib20,gtk20,libwnck
GTK2_CONFIGURE_ON=	--with-gtk=2.0

GTK3_IMPLIES=	DBUS
GTK3_USE=	GNOME=glib20,gtk30,libwnck3
GTK3_CONFIGURE_ON=	--with-gtk=3.0

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CONFIGURE_ENABLE=	inotify

MATE_CONFIGURE_ENABLE=	mate

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

SVG_USE=	GNOME=librsvg2
SVG_CONFIGURE_ENABLE=	librsvg

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -E 's@\[\[@[@g;s@\]\]@]@g;' ${SHEBANG_FILES} && \
		${REINPLACE_CMD} -E 's@librsvg-@rsvg-@;s@<librsvg/@<librsvg-2.0/librsvg/@' plugins/svg.c

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/compiz-manager ${STAGEDIR}${PREFIX}/bin/compiz-manager
	${INSTALL_DATA} ${FILESDIR}/compiz-manager.png ${STAGEDIR}${DATADIR}/compiz-manager.png

.include <bsd.port.mk>

PORTNAME=	compiz
PORTVERSION=	0.8.18
CATEGORIES=	x11-wm

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Compiz Composite/Window Manager

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
		${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_amd64=	nvidia-settings:x11/nvidia-settings
RUN_DEPENDS_i386=	nvidia-settings:x11/nvidia-settings

USES=		autoreconf:build gl gmake gnome iconv libtool localbase pathfix \
		pkgconfig shebangfix xorg
USE_GL=		gl glu
USE_GNOME=	cairo glib20 intltool
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama \
		xorgproto xrandr xrender xcursor

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_PROJECT=	compiz-core
GL_COMMIT=	ae031701f5f8b43cf6a03262fbabc779bd35ad80
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	ae03170

INSTALL_TARGET=	install-strip
INSTALL_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-menu-entries --disable-dependency-tracking

OPTIONS_DEFINE=	DBUS FUSE INOTIFY MATE NLS SVG
OPTIONS_DEFAULT=	DBUS GTK3 NLS SVG
OPTIONS_RADIO=	GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_SUB=	yes

INOTIFY_DESC=	inotify plugin support

SUB_FILES=		compiz-manager
DESKTOP_ENTRIES=	"Compiz Manager" \
			"Wrapper script for starting compiz" \
			"${DATADIR}/compiz-manager.png" \
			"compiz-manager" \
			"System;Core;" \
			false

SHEBANG_FILES=	plugins/compiz-decorator
bash_CMD=	/bin/sh

GLIB_SCHEMAS=	org.compiz-0.gwd.gschema.xml

DBUS_CONFIGURE_ENABLE=	dbus dbus-glib
DBUS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
DBUS_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=		fuse

GTK2_CONFIGURE_ON=	--with-gtk=2.0
GTK2_USE=	gnome=glib20,gtk20,libwnck
GTK2_IMPLIES=	DBUS

GTK3_CONFIGURE_ON=	--with-gtk=3.0
GTK3_USE=	gnome=glib20,gtk30,libwnck3
GTK3_IMPLIES=	DBUS

INOTIFY_CONFIGURE_ENABLE=	inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

MATE_CONFIGURE_ENABLE=	mate

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

SVG_CONFIGURE_ENABLE=	librsvg
SVG_USE=	gnome=librsvg2

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -E 's@\[\[@[@g;s@\]\]@]@g;' ${SHEBANG_FILES} && \
		${REINPLACE_CMD} -E 's@librsvg-@rsvg-@;s@<librsvg/@<librsvg-2.0/librsvg/@' plugins/svg.c

pre-configure:
	@cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} autogen.sh ${CONFIGURE_ARGS}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/compiz-manager ${STAGEDIR}${PREFIX}/bin/compiz-manager
	${INSTALL_DATA} ${FILESDIR}/compiz-manager.png ${STAGEDIR}${DATADIR}/compiz-manager.png

.include <bsd.port.mk>

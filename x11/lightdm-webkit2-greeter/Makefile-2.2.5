PORTNAME=	lightdm-webkit2-greeter
PORTVERSION=	2.2.5
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Web Greeter for LightDM
WWW=		https://github.com/antergos/web-greeter

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		liblightdm-gobject-1.so:x11/lightdm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		gettext gmake gnome localbase meson pkgconfig python shebangfix xorg
USE_GNOME=	glib20 gtk30
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	Antergos

WRKSRC=	${WRKDIR}/web-greeter-${PORTVERSION}

MESON_BUILD_DIR=	build

SHEBANG_FILES=	build/utils.sh


post-patch:
	${REINPLACE_CMD} -e 's@/usr@${PREFIX}@;s@/etc@${PREFIX}/etc@' ${WRKSRC}/meson_options.txt ${WRKSRC}/data/lightdm-webkit2-greeter.conf ${WRKSRC}/man/${PORTNAME}.1
	${REINPLACE_CMD} -e 's@canonicalize_file_name(file_path)@realpath(file_path, NULL)@' ${WRKSRC}/src/webkit2-extension.c

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/lightdm/${PORTNAME}.conf.sample

.include <bsd.port.mk>

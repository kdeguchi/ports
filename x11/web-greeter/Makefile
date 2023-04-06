PORTNAME=	web-greeter
PORTVERSION=	3.0.0rc2
CATEGORIES=	x11

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Web Greeter for LightDM
WWW=		https://github.com/antergos/web-greeter

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed \
		pyrcc5:devel/py-qt5-pyqt \
		zip:archivers/zip
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		liblightdm-gobject-1.so:x11/lightdm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	whither>0:devel/whither

USES=		gettext gmake gnome localbase pkgconfig python shebangfix xorg
USE_GNOME=	glib20 gtk30
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	Antergos
GH_TAGNAME=	9252419

WRKSRC=	${WRKDIR}/web-greeter-${GH_TAGNAME}

SHEBANG_FILES=	build/utils.sh dist/Xgreeter

MAKE_ARGS+=	config_dir=${PREFIX}/etc/lightdm
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's@/etc@$${PREFIX}/etc@;s@-fprint@>@;s@/tmp/@${WRKSRC}/@;s@cp -R -t .*@cp -R "$${REPO_DIR}/web-greeter" "$${REPO_DIR}/dist"  "$${BUILD_DIR}"@;s@@@;s@sed @gsed @' ${WRKSRC}/build/utils.sh
	${REINPLACE_CMD} -e 's@/usr/lib/at-spi2-core@/usr/local/libexec@' ${WRKSRC}/web-greeter/whither.yml
	${REINPLACE_CMD} -e 's@/etc@${PREFIX}/etc@' ${WRKSRC}/dist/90-greeter-wrapper.conf

.include <bsd.port.mk>

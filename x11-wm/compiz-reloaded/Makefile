PORTNAME=	compiz-reloaded
PORTVERSION=	0.8.18
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Metaport of compiz-reloaded
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+ LGPL21+ MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libcompizconfig.so:x11-wm/libcompizconfig
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
		${LOCALBASE}/lib/compiz/libanimation.so:x11-wm/compiz-plugins-main \
		${LOCALBASE}/bin/ccsm:x11-wm/ccsm

USES=		gnome metaport xorg
USE_GNOME=	libxslt
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xrandr

OPTIONS_DEFINE=	EMERALD EXPERIMENTAL EXTRA
OPTIONS_DEFAULT=	EMERALD EXTRA

EMERALD_DESC=	Enable emerald window decorator
EXPERIMENTAL_DESC=	Enable experimental plugins
EXTRA_DESC=	Enable extra plugins

EMERALD_RUN_DEPENDS=	${LOCALBASE}/bin/emerald:x11-wm/emerald \
			${LOCALBASE}/share/emerald/themes/Adonis_Mod/theme.ini:x11-themes/emerald-themes

EXPERIMENTAL_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libanimationplus.so:x11-wm/compiz-plugins-experimental

EXTRA_RUN_DEPENDS=	${LOCALBASE}/lib/compiz/libaddhelper.so:x11-wm/compiz-plugins-extra

.include <bsd.port.mk>

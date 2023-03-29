PORTNAME=	libXpm
PORTVERSION=	3.5.15
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Pixmap library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto x11 xext xt
LDFLAGS+=	-L${LOCALBASE}/lib

CPE_VENDOR=	libxpm_project

OPTIONS_DEFINE=		MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_ENV_OFF=	ac_cv_search_gettext=no

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

PORTNAME=	compizconfig-python
PORTVERSION=	0.8.18
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python bindings for the compizconfig library
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:x11-wm/libcompizconfig

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:x11-wm/libcompizconfig

USES=		autoreconf gettext-runtime gmake gnome libtool \
		pathfix pkgconfig python xorg

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	17f5f7548b30c88850c2564d9837c53e0eb035ff

USE_GNOME=	glib20 libxml2
USE_PYTHON=	flavors cython
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xrandr xcursor xi

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cython=cython-${PYTHON_VER}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/compizconfig.so

.include <bsd.port.mk>

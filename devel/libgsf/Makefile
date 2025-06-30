PORTNAME=	libgsf
DISTVERSION=	1.14.54
CATEGORIES=	devel
#MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Structured file library from GNOME
WWW=		https://gitlab.gnome.org/GNOME/libgsf/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

USES=		autoreconf cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome

USE_GITLAB=	yes
GL_SITE=		https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	d479829443d3bea401732df7e045813adaf57238

USE_GNOME=	gdkpixbuf glib20 intlhack introspection:build libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-introspection

INSTALL_TARGET=	install-strip

PLIST_SUB+=	LIBMINORVER=${DISTVERSION:E} \
		LIBSHORTVER=${DISTVERSION:R:S/.//}

OPTIONS_DEFINE=	GTKDOC NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

GTKDOC_CONFIGURE_ENABLE=	gtk-doc

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

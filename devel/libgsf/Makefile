PORTNAME=	libgsf
DISTVERSION=	1.14.53
CATEGORIES=	devel
#MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Extensible I/O abstraction for dealing with structured file formats
WWW=		http://www.gnumeric.org

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

USES=		autoreconf cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome

USE_GITLAB=	yes
GL_SITE=		https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	634340d31177c02ccdb43171e37291948e7f8974

USE_GNOME=	gdkpixbuf2 glib20 intlhack introspection:build libxml2
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

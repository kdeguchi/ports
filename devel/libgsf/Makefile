PORTNAME=	libgsf
PORTVERSION=	1.14.51
CATEGORIES=	devel
#MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Extensible I/O abstraction for dealing with structured file formats
WWW=		http://www.gnumeric.org

LICENSE=	GPLv2 #LGPL21
#LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
#LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

USES=		autoreconf cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome

USE_GITLAB=	yes
GL_SITE=		https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	503453ba

USE_GNOME=	gdkpixbuf2 intlhack introspection:build libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection
INSTALL_TARGET=	install-strip

CFLAGS+=	-fwritable-strings

PLIST_SUB+=	LIBMINORVER=${PORTVERSION:E} \
		LIBSHORTVER=${PORTVERSION:R:S/.//}

OPTIONS_DEFINE=	GTKDOC NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

GTKDOC_CONFIGURE_ENABLE=	gtk-doc

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

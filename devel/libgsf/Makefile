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
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	503453ba
WRKSRC=	${WRKDIR}/libgsf-503453ba-503453ba1ee1220b2e18d2e8e5261f7585a8d2df
USE_GNOME=	gdkpixbuf2 intlhack introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection
CPE_VENDOR=	gnome

OPTIONS_DEFINE=	GTKDOC NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

GTKDOC_CONFIGURE_ENABLE=	gtk-doc

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

PLIST_SUB+=	LIBMINORVER=${PORTVERSION:E} \
		LIBSHORTVER=${PORTVERSION:R:S/.//}

.include <bsd.port.mk>

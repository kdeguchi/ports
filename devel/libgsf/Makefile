PORTNAME=	libgsf
DISTVERSION=	1.14.57
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Structured file library from GNOME
WWW=		https://gitlab.gnome.org/GNOME/libgsf/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	gdkpixbuf glib20 libxml2 introspection:build
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_TAGNAME=	680a829d7dc6d9da01c4832a14bf397a2315fde1

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-introspection

INSTALL_TARGET=	install-strip

PLIST_SUB+=	LIBMINORVER=${DISTVERSION:E} \
		LIBSHORTVER=${DISTVERSION:R:S/.//}

OPTIONS_DEFINE=	GTKDOC NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

GTKDOC_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
GTKDOC_CONFIGURE_ENAABLE=	gtk-doc
NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

post-patch:
.if ${PORT_OPTIONS:MGTKDOC}
	@${DO_NADA}
.else
	${REINPLACE_CMD} -e '/^GTK_DOC_CHECK.*/d' \
		-e 's/gtk_doc_installed=true/gtk_doc_installed=false/' \
			${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e '/^if GTK_DOC_INSTALLED/d' \
		-e '/^include \$$(top_srcdir).*/d' \
		-e '/^CLEANFILES += gsf-scan.*/d' \
		-e '/^\.PHONY : dist-hook-local/d' \
		-e '/^EXTRA_DIST += \$$(manpage_DATA)/d' \
		-e '/^else/d' \
		-e '/^endif/d' \
			${WRKSRC}/doc/Makefile.am
.endif

.include <bsd.port.post.mk>

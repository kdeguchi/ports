PORTNAME=	sylpheed-autoenc-plugin
PORTVERSION=	1.0.2
CATEGORIES=	mail

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Sylpheed plug-in to encrypt attached files

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libsylpheed-plugin-0.so:mail/sylpheed \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	7zz:archivers/7-zip

USES=		gettext gnome libtool localbase pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	xorgproto
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk20 pango

USE_GITHUB=	yes
GH_ACCOUNT=	y-hiroyu
GH_TAGNAME=	0f2b2ed

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS= --prefix=${PREFIX}

PLIST_FILES=	lib/sylpheed/plugins/autoenc.so \
		share/locale/ja/LC_MESSAGES/autoenc.mo

.include <bsd.port.mk>

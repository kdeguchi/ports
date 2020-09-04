# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD: audio/osd-lyrics/Makefile 2552 2020-06-11 05:18:59Z  $

PORTNAME=	osdlyrics
PORTVERSION=	0.5.5.rc2
CATEGORIES=	audio deskutils
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	On-screen lyrics display program for various media players

LICENSE=	GPLv3

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycurl>=0:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}

USES=		autoreconf desktop-file-utils gettext-tools gmake gnome \
		iconv localbase pkgconfig python xorg

USE_GITHUB=	yes
GH_TAGNAME=	88efbe3

USE_GNOME=	atk glib20 gtk20 intltool pango pygobject3
USE_PYTHON=	autoplist flavors py3kplist
USE_XORG=	x11
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch-NLS-on:
	@${CP} ${FILESDIR}/ja.po ${WRKSRC}/po/
	@${ECHO_CMD} ' ja' >> ${WRKSRC}/po/LINGUAS

post-configure-NLS-off:
	@${REINPLACE_CMD} -E -e 's,(USE_NLS=)yes,\1no,' ${WRKSRC}/configure

.include <bsd.port.mk>

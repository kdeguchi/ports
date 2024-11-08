PORTNAME=	libcompizconfig
PORTVERSION=	0.8.18
PORTREVISION=	4
CATEGORIES=	x11-wm

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Alternative configuration system for Compiz
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		autoreconf gmake gnome libtool localbase pathfix pkgconfig xorg

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	2ee9952ce5aac8e7d4e676f692acace1ecc088e6

USE_GNOME=	intltool libxml2
USE_LDCONFIG=	yes
USE_XORG=		x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lpthread

OPTIONS_DEFINE=	INOTIFY
OPTIONS_DEFAULT=	INOTIFY

INOTIFY_DESC?=	Enable inotify support
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_LDFLAGS=	-linotify

post-patch:
	@echo "OSVERSION=${OSVERSION}"
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/src/main.c			\
		${WRKSRC}/src/lists.c			\
		${WRKSRC}/src/filewatch.c		\
		${WRKSRC}/src/ini.c			\
		${WRKSRC}/backend/ini.c

post-patch-INOTIFY-off:
	@${REINPLACE_CMD} -e 's|.*sys/inotify\.h.*||' ${WRKSRC}/configure.ac

.include <bsd.port.mk>

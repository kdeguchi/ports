PORTNAME=	pcsc-lite
PORTVERSION=	2.0.0
CATEGORIES=	security
MASTER_SITES=	https://pcsclite.apdu.fr/files/

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Middleware to access a smart card using SCard API (PC/SC)
WWW=		https://pcsclite.apdu.fr/

LICENSE=	GPLv3+

USES=	tar:bz2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipcdir=/var/run/pcscd \
		--runstatedir=/var/run \
		--disable-libsystemd \
		--disable-serial \
		--disable-usb \
		--disable-libudev

OPTIONS_DEFINE=	DOCS POLKIT
OPTIONS_SUB=	yes

POLKIT_DESC=	Build with Polkit support
POLKIT_CONFIGURE_ENABLE=	polkit
POLKIT_LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

.include <bsd.port.mk>

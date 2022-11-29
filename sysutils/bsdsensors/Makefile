PORTNAME=	bsdsensors
PORTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Getting sensor values on FreeBSD

WWW=	https://github.com/HenryHu/bsdsensors

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog

USES=		cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	HenryHu
GH_TAGNAME=	87754d9

OPTIONS_DEFINE=	SUID
OPTIONS_SUB=	yes

SUID_DESC=	Install with setuid bit

SUID_VARS=	PLIST_SUB=SUID="@(,,4755) "
SUID_VARS_OFF=	PLIST_SUB=SUID=""

.include <bsd.port.mk>

PORTNAME=	libproxy
PORTVERSION=	0.4.11
DISTVERSIONSUFFIX=	-11.el7
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library that provides automatic proxy configuration management (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${PORTSDIR}/net/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

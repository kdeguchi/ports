PORTNAME=	gstreamer1
PORTVERSION=	1.10.4
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	multimedia linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GStreamer streaming media framework runtime (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${PORTSDIR}/multimedia/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

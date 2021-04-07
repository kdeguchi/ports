PORTNAME=	orc
PORTVERSION=	0.4.26
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=	${PORTSDIR}/devel/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

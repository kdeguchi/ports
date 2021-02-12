# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD: head/multimedia/linux-c7-libtheora/Makefile 503741 2019-06-08 15:59:46Z tijl $

PORTNAME=	libmodman
PORTVERSION=	2.0.1
DISTVERSIONSUFFIX=	-8.el7
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library for managing C++ modules (plug-ins) (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD: head/multimedia/gstreamer1-plugins/Makefile 563995 2021-02-04 06:04:50Z bapt $

PORTNAME=	gstreamer1-plugins
PORTVERSION=	1.10.4
DISTVERSIONPREFIX=	base-
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES?=	multimedia audio linux

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

LICENSE=	LGPL20+

USES=	linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	gstreamer1 libvorbis libtheora orc
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=	${PORTSDIR}/multimedia/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

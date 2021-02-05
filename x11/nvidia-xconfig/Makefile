# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD: head/x11/nvidia-xconfig/Makefile 540871 2020-06-30 08:42:18Z danfe $

PORTNAME=	nvidia-xconfig
PORTVERSION=	460.32.03
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Tool to manipulate X configuration files for the NVidia driver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA

MAKE_ENV=	NV_VERBOSE= \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		prefix=${PREFIX}

PLIST_FILES=	bin/nvidia-xconfig \
		man/man1/nvidia-xconfig.1.gz

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^MANDIR/s|share/||' \
		${WRKSRC}/utils.mk

.include <bsd.port.mk>

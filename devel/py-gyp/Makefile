# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD: devel/py-gyp/Makefile 2543 2020-06-08 03:28:11Z  $

PORTNAME=	gyp
PORTVERSION=	20200512
CATEGORIES=	devel python
MASTER_SITES=	https://chromium.googlesource.com/external/gyp/+archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	caa60026e223fc501e8b337fd5086ece4028b1c6.tar.gz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Build System That Generates Other Build Systems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	allflavors autoplist concurrent distutils
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

.include <bsd.port.mk>

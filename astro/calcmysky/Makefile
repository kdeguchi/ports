PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	astro

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Planetary atmosphere light scattering simulator
WWW=		https://github.com/10110111/CalcMySky

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake:testing eigen:3 localbase

.if ${FLAVOR} == qt6
USES+=		qt:6
USE_QT=	base
.elif ${FLAAVOR} == qt5
USES+=		qt:5
USE_QT=	buildtools:build qmake:build core gui opengl widgets
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	10110111
GH_PROJECT=	CalcMySky

CMAKE_ARGS=	-DQT_VERSION:STRING=${_QT_VER}

PLIST_SUB=	QTVER=${_QT_VER}

.include <bsd.port.mk>

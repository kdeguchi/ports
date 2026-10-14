PORTNAME=	nvidia-drm-61-kmod
PORTREVISION=	0
CATEGORIES=	graphics

RUN_DEPENDS+=	${KMODDIR}/drm.ko:graphics/drm-61-kmod
CONFLICTS_INSTALL=	nvidia-drm-515-kmod* nvidia-drm-66-kmod* nvidia-drm-612-kmod* nvidia-drm-latest-kmod*

DRM_VER=	61

.include "${.CURDIR}/../drm-61-kmod/Makefile.version"
.include "${.CURDIR}/../nvidia-drm-kmod/Makefile.common"

.include <bsd.port.mk>

PORTNAME=	simple-ccsm
PORTVERSION=	0.8.18
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python/GTK based settings manager for CompizConfig
WWW=		https://github.com/compiz-reloaded

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:x11-wm/compizconfig-python

USES=		gettext gnome python

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	85dd9f9fead8e33782105ab04dd9cb66446f4dd4

USE_GNOME=	intltool pygobject3
USE_PYTHON=	flavors py3kplist

NO_BUILD=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --root=${STAGEDIR} --prefix=${PREFIX})

.include <bsd.port.mk>

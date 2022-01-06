# Created by: Robert Noland <rnoland@FreeBSD.org>

PORTNAME=	simple-ccsm
PORTVERSION=	0.8.18
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python/GTK based settings manager for CompizConfig

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:x11-wm/compizconfig-python

USES=		gettext gnome python
USE_GNOME=	intltool pygobject3
USE_PYTHON=	flavors py3kplist

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	1c2ecc26b2868a793b8fe089b6a2391251f8da98
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	1c2ecc2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --root=${STAGEDIR} --prefix=${PREFIX})

.include <bsd.port.mk>

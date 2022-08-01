PORTNAME=	ccsm
PORTVERSION=	0.8.18
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python/GTK based settings manager for CompizConfig

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:x11-wm/compizconfig-python

USES=		gmake gnome python
USE_GNOME=	intltool pygobject3
USE_PYTHON=	flavors py3kplist
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	8fcfded12b1c8febc4e1e9dc08d082286985fce4
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	8fcfded

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

post-patch:
	${REINPLACE_CMD} 's,@python ,@${PYTHON_CMD} ,' ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --root=${STAGEDIR} --prefix=${PREFIX})

.include <bsd.port.mk>

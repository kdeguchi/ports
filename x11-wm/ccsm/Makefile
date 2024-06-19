PORTNAME=	ccsm
PORTVERSION=	0.8.18
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Python/GTK based settings manager for CompizConfig
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compizconfig-python.pc:x11-wm/compizconfig-python

USES=		gmake gnome python

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	0cc706c1c741a8234da3bd1a2c0460cae2804820

USE_GNOME=	intltool pygobject3
USE_PYTHON=	autoplist distutils flavors py3kplist
PYDISTUTILS_INSTALLNOSINGLE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime gettext-tools
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} 's,@python ,@${PYTHON_CMD} ,' ${WRKSRC}/Makefile

do-configure:
	@${DO_NADA}

post-install-NLS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/share/locale

.include <bsd.port.mk>

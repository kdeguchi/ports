PORTNAME=	fusion-icon
PORTVERSION=	0.2.4
CATEGORIES=	x11-wm

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Compiz tray (indicator) icon
WWW=		https://github.com/compiz-reloaded

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>0:devel/pyside2@${PY_FLAVOR}

USES=		gnome python shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	f39d989cf070470e3f75685b9c00552923f39187

USE_GNOME=	intltool:build

USE_PYTHON=	autoplist flavors distutils
PYDISTUTILS_INSTALLNOSINGLE=	yes

SHEBANG_FILES=	setup.py fusion-icon

.include <bsd.port.mk>

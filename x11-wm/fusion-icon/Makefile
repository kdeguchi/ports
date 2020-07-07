# $FreeBSD: x11-wm/fusion-icon/Makefile 2548 2020-06-08 04:01:12Z  $

PORTNAME=	fusion-icon
PORTVERSION=	0.2.4
CATEGORIES=	x11-wm

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Compiz tray (indicator) icon

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>0:devel/pyside2@${PY_FLAVOR}

USES=		python shebangfix
USE_GNOME=	intltool:build
USE_PYTHON=	autoplist flavors distutils

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	f39d989cf070470e3f75685b9c00552923f39187

INSTALL_ICONS=	yes

SHEBANG_FILES=	setup.py fusion-icon

PYDISTUTILS_INSTALLNOSINGLE=	yes

.include <bsd.port.mk>

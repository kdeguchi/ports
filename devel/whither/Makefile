PORTNAME=	whither
PORTVERSION=	0.3.2
CATEGORIES=	devel python

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Universal Linux Application SDK
WWW=	https://github.com/Antergos/whither

LIB_DEPENDS=	libQt5WebEngine.so:www/qt5-webengine
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml

USES=	gnome python pyqt:5 qt:5
USE_PYTHON=	autoplist distutils flavors py3kplist
USE_GNOME=	pygobject3
USE_PYQT=	webengine

USE_GITHUB=	yes
GH_ACCOUNT=	Antergos

.include <bsd.port.mk>

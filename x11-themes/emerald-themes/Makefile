PORTNAME=	emerald-themes
PORTVERSION=	0.8.18
CATEGORIES=	x11-themes

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Themes for the Emerald Window Decorator
WWW=		https://github.com/compiz-reloaded

BUILD_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake localbase shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	b01e7ed2ccc839bdc9e58c41713021f413f9fa87
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	b01e7ed

SHEBANG_FILES=	themes/import.sh
GNU_CONFIGURE=	yes

NO_ARCH=	yes

post-install:
	${FIND} ${STAGEDIR} -name '*.bak' -delete

.include <bsd.port.mk>

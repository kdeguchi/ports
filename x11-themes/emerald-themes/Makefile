# $FreeBSD: x11-themes/emerald-themes/Makefile 2512 2020-05-14 23:46:56Z  $

PORTNAME=	emerald-themes
PORTVERSION=	0.8.18
CATEGORIES=	x11-themes

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Themes for the Emerald Window Decorator

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

.include <bsd.port.mk>

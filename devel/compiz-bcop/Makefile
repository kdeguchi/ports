# Created by: Robert Noland <rnoland@FreeBSD.org>

PORTNAME=	compiz-bcop
PORTVERSION=	0.8.18
CATEGORIES=	devel x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Code generator for Compiz Fusion Plugins

RUN_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt

HAS_CONFIGURE=	yes

USES=		autoreconf gnome pathfix pkgconfig shebangfix
USE_GNOME=	libxslt

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	cbf12c741fd292ad86c6dd96329af515c2f054d6
#USE_GITHUB=	yes
#GH_ACCOUNT=	compiz-reloaded
#GH_TAGNAME=	cbf12c7

SHEBANG_FILES=	src/bcop.in
bash_CMD=	${SH}

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-E -e 's|^function usage|usage()|' \
		-e 's|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/src/bcop.in

.include <bsd.port.mk>

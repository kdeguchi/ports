PORTNAME=	compiz-bcop
PORTVERSION=	0.8.18
PORTREVISION=	1
CATEGORIES=	devel x11-wm

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Code generator for Compiz Fusion Plugins
WWW=		https://github.com/compiz-reloaded

RUN_DEPENDS=	getopt>=0:misc/getopt

USES=		autoreconf gnome pathfix pkgconfig shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	compiz
GL_COMMIT=	cbf12c741fd292ad86c6dd96329af515c2f054d6
USE_GNOME=	libxslt

SHEBANG_FILES=	src/bcop.in
bash_CMD=	${SH}

HAS_CONFIGURE=	yes

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-E -e 's|^function usage|usage()|' \
		-e 's|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/src/bcop.in

.include <bsd.port.mk>

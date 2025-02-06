PORTNAME=	nerd-fonts
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	x11-fonts

MAINTAINER=	gregf@hugops.pw
COMMENT=	Developer-targeted fonts with a high number of glyphs
WWW=		https://nerdfonts.com/

LICENSE=	MIT

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	ryanoasis

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_SINGLE=	FAMILY
OPTIONS_SINGLE_FAMILY=	ALL SYMBOLS

OPTIONS_DEFAULT=	ALL

FAMILY_DESC=	Fonts to install
ALL_DESC=	all fonts
SYMBOLS_DESC=	"Symbols Nerd Font" only

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions \
			--exclude '*.md' \
			--exclude '*Awesome*' \
			--exclude '*Linux*' \
			--exclude '*Octicons*' \
			--exclude '*Pomicons*' \
			--exclude '*Windows*'

.if ${PORT_OPTIONS:MSYMBOLS}
EXTRACT_AFTER_ARGS+=	--include ${PKGNAME}/patched-fonts/NerdFontsSymbolsOnly
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC}/patched-fonts && \
		${COPYTREE_SHARE} . ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>

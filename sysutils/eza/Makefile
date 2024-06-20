PORTNAME=	eza
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.19
CATEGORIES=	sysutils
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern, maintained replacement for ls
WWW=		https://eza.rocks/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eza-community

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_GROUP=	COMPLETIONS
OPTIONS_GROUP_COMPLETIONS=	BASH FISH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/${PORTNAME}.bash
FISH_PLIST_FILES=	share/fish/completions/${PORTNAME}.fish

MANPAGES_MASTER_SITES=	https://github.com/eza-community/eza/releases/download/v${DISTVERSION}/
MANPAGES_DISTFILES=	man-${DISTVERSION}.tar.gz
_MAN_FILES=	eza.1 eza_colors-explanation.5 eza_colors.5
.for i in ${_MAN_FILES}
MANPAGES_PLIST_FILES+=	share/man/man${i:C/.*\.//}/${i}.gz
.endfor

ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/bash/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish

post-install-MANPAGES-on:
.for i in ${_MAN_FILES}
	${INSTALL_MAN} ${WRKDIR}/target/man-${DISTVERSION}/${i} ${STAGEDIR}${PREFIX}/share/man/man${i:C/.*\.//}
.endfor

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>

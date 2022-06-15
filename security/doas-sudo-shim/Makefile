PORTNAME=	doas-sudo-shim
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	doas shimulatets sudo

NO_BUILD=	yes

RUN_DEPENDS=	doas:secrity/doas

CONFLICTS_INSTALL= sudo

SUB_FILES=	sudo.sh
PLIST_FILES=	bin/sudo bin/sudoedit

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sudo.sh ${STAGEDIR}${PREFIX}/bin/sudo
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s doasedit sudoedit

.include <bsd.port.mk>

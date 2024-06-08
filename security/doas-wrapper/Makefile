PORTNAME=	doas-wrapper
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Wrapper script for doas

RUN_DEPENDS=	doas:security/doas

CONFLICTS_INSTALL= sudo

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	sudo.sh
PLIST_FILES=	bin/sudo bin/sudoedit bin/visudo

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sudo.sh ${STAGEDIR}${PREFIX}/bin/sudo
	cd ${STAGEDIR}/${PREFIX}/bin && \
		${RLN} doasedit sudoedit && \
		${RLN} vidoas visudo

.include <bsd.port.mk>

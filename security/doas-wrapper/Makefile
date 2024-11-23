PORTNAME=	doas-wrapper
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Wrapper script for doas

CONFLICTS_INSTALL= sudo

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/sudo bin/sudoedit bin/visudo
PLIST_SUB=	DOAS_CONF=${PREFIX}/etc/doas.conf
SUB_FILES=	doasedit.8 doasedit.sh sudo.sh vidoas.8 vidoas.sh

OPTIONS_SINGLE=	DOAS_WRAPPER
OPTIONS_SINGLE_DOAS_WRAPPER=	DOAS OPENDOAS

DOAS_DESC=	OpenBSD's doas
OPENDOAS_DESC=	OpenDoas

DOAS_RUN_DEPENDS=	doas:security/doas

OPENDOAS_RUN_DEPENDS=	doas:security/opendoas
OPENDOAS_PLIST_FILES=	bin/doasedit \
		bin/vidoas \
		share/man/man8/doasedit.8.gz \
		share/man/man8/vidoas.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sudo.sh ${STAGEDIR}${PREFIX}/bin/sudo
	cd ${STAGEDIR}/${PREFIX}/bin && \
		${RLN} doasedit sudoedit && \
		${RLN} vidoas visudo

do-install-OPENDOAS-on:
	${INSTALL_SCRIPT} ${WRKDIR}/doasedit.sh ${STAGEDIR}${PREFIX}/bin/doasedit
	${INSTALL_MAN} ${WRKDIR}/doasedit.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_SCRIPT} ${WRKDIR}/vidoas.sh ${STAGEDIR}${PREFIX}/bin/vidoas
	${INSTALL_MAN} ${WRKDIR}/vidoas.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>

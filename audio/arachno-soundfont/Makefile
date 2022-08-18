PORTNAME=	arachno-soundfont
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	# fetch manually from https://www.dropbox.com/s/2rnpya9ecb9m4jh/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}-sf2

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Arachno sound fonts

RESTRICTED=	Manual download from https://www.dropbox.com/s/2rnpya9ecb9m4jh/arachno-soundfont-10-sf2.zip

LICENSE=	ARACHNO
LICENSE_NAME=	arachno
LICENSE_FILE=	${WRKSRC}/Read\ Me.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell no-auto-accept

NO_ARCH=	yes
NO_BUILD=	yes

USES=	zip

PLIST_FILES=	share/sounds/sf2/Arachno\ SoundFont\ -\ Version\ 1.0.sf2 \
			share/timidity/ArachnoSoundFont.cfg

SUB_FILES=	ArachnoSoundFont.cfg
SUB_LIST=	PREFIX=${PREFIX}

post-extract:
	@${MKDIR} ${WRKSRC}
	cd ${WRKDIR} && ${MV} [A-Z]* sfArk ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/sounds/sf2
	${INSTALL_DATA} ${WRKSRC}/Arachno\ SoundFont\ -\ Version\ 1.0.sf2 \
		${STAGEDIR}${PREFIX}/share/sounds/sf2
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/timidity
	${INSTALL_DATA} ${WRKDIR}/ArachnoSoundFont.cfg \
		${STAGEDIR}${PREFIX}/share/timidity

.include <bsd.port.mk>

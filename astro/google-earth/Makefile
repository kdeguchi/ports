# $FreeBSD: head/astro/google-earth/Makefile 432956 2017-01-31 20:51:04Z tijl $

PORTNAME=	google-earth
PORTVERSION=	7.3.3
#PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	astro deskutils geography
MASTER_SITES=	https://dl.google.com/dl/earth/client/current/
DISTFILES_amd64=google-earth-pro-stable-current.x86_64.rpm
#DISTFILES_i386=	google-earth-pro-stable_current_i386.rpm
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual globe, map and geographical information program

RESTRICTED=	Not really sure about the redistribution terms

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
USES=		desktop-file-utils linux
USE_LINUX=	dri xorglibs

post-patch:
	@${SED} -i '' 's/^Exec=[^[:space:]]*/Exec=googleearth/' \
		${WRKSRC}/opt/google/earth/pro/google-earth-pro.desktop

do-install:
.for s in 16 22 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/opt/google/earth/pro/product_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/google-earth.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/opt/google/earth/pro/google-earth-pro.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${LINUXBASE}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opt ${STAGEDIR}${LINUXBASE})
	${CHMOD} +x ${STAGEDIR}${LINUXBASE}/opt/google/earth/pro/googleearth-bin
	${INSTALL_SCRIPT} ${FILESDIR}/googleearth ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

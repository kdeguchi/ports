PORTNAME=	aquantia-atlantic-kmod
PORTVERSION=	0.2.0
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aquantia AQtion (Atlantic) Network Driver (Development Preview)
WWW=		https://github.com/albb0920/aqtion-freebsd-aq2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod uidfix
USE_GITHUB=	yes

GH_ACCOUNT=	albb0920
GH_PROJECT=	aqtion-freebsd-aq2
GH_TAGNAME=	2774d01

PLIST_FILES=	${KMODDIR}/if_atlantic.ko

.include <bsd.port.mk>

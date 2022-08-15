PORTNAME=	libxaw3dxft
DISTVERSION=	1.6.2h
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/sf-xpaint/${PORTNAME}
DISTNAME=	libXaw3dXft-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Xaw (Athena Widget Set) replacement with extended fonts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		libtool pathfix pkgconfig tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xft xmu xpm xt
USE_LDCONFIG=	yes

SUB_FILES=	pkg-post-deinstall pkg-post-install
PKGPOSTINSTALL=	${WRKDIR}/pkg-post-install
PKGPOSTDEINSTALL=	${WRKDIR}/pkg-post-deinstall

INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--enable-internationalization --enable-arrow-scrollbars
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2

DOCSDIR=	${LOCALBASE}/share/doc/libXaw3dXft
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/^typedef.*Pixel;/d' ${WRKSRC}/src/Xaw3dXft.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/.${PORTNAME}
	${MV} ${STAGEDIR}${PREFIX}/lib/libXaw3dxft* \
		${STAGEDIR}${PREFIX}/lib/.${PORTNAME}
.for i in libXaw.so libXaw.so.6 libXaw6.so libXaw6.so.6 libXaw6.so.6.0.1 \
	libXaw.so.7 libXaw7.so libXaw7.so.7 libXaw7.so.7.0.0 libXaw3d.so libXaw3d.so.8
	${RLN} ${STAGEDIR}${PREFIX}/lib/.${PORTNAME}/libXaw3dxft.so \
		${STAGEDIR}${PREFIX}/lib/.${PORTNAME}/${i}
.endfor

.include <bsd.port.mk>

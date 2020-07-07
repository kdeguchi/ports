# $FreeBSD: sysutils/libcdio-paranoia/Makefile 2407 2020-03-11 00:58:10Z  $

PORTNAME=	libcdio-paranoia
PORTVERSION=	10.2+2.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GNU/libcdio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Read audio from the CDROM directly as data

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdio.so:sysutils/libcdio

USES=		compiler:c11 gmake iconv libtool localbase pathfix perl5 pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-versioned-libs
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
	${REINPLACE_CMD} -e 's|/jp/man1|/ja/man1|' \
		${WRKSRC}/doc/ja/Makefile.in
	${REINPLACE_CMD} -e 's|freebsd10\.\*|freebsd[1-9][0-9].*|' \
		${WRKSRC}/configure
	cd ${WRKSRC}/doc/ja && \
		${CAT} cd-paranoia.1.in | ${ICONV_CMD} -f EUC-JP -t UTF-8 > cd-paranoia.1.in.utf-8 && \
		${MV} -f cd-paranoia.1.in.utf-8 cd-paranoia.1.in

.include <bsd.port.mk>

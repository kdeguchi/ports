PORTNAME=	timidity++
PORTVERSION=	2.15.0
PORTREVISION=	1
CATEGORIES+=	audio
MASTER_SITES=	SF/timidity/TiMidity%2B%2B/TiMidity%2B%2B-${PORTVERSION}
DISTNAME=	TiMidity++-${PORTVERSION}

MAINTAINER?=	fuz@FreeBSD.org
COMMENT?=	Software MIDI player
WWW=		https://timidity.sourceforge.net/

LICENSE=	GPLv2+

LIB_DEPENDS=	libarc.so:archivers/libarc
.if !defined(PKGNAMESUFFIX)
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
RUN_DEPENDS=	eawpats>0:audio/eawpats
.endif

USES=		gmake iconv:build localbase tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	SHLD="${CC} -shared"

CPPFLAGS+=	-I${LOCALBASE}/include/libarc
LDFLAGS+=	-Wl,--export-dynamic

PLIST_SUB+=	TIMID_LIBDIR="${TIMID_LIBDIR}" EUCJP_LOCALE="${EUCJP_LOCALE}"

.if !defined(PKGNAMESUFFIX)
OPTIONS_DEFINE=		DOCS EAWPLUS X11
OPTIONS_DEFAULT=	X11
CONFIGURE_ARGS+=	--enable-audio=oss,vorbis
EAWPLUS_DESC=		Collection of Gravis Ultrasound MIDI patches
EAWPLUS_RUN_DEPENDS=	eawplus>0:audio/eawplus
X11_LIB_DEPENDS=	libpng.so:graphics/png
X11_USES=		xorg
X11_USE=		XORG=x11,xext,xft
X11_CONFIGURE_ON=	--with-x --enable-xft --enable-spectrogram --enable-wrd \
			--enable-dynamic
X11_CONFIGURE_OFF=	--without-x --disable-xft --disable-spectrogram --disable-wrd \
			--disable-dynamic
X11_CPPFLAGS=		$$(libpng-config --I_opts)
.endif

TIMID_LIBDIR=	lib/timidity
EUCJP_LOCALE=	ja_JP.eucJP

.include <bsd.port.options.mk>

.if defined(PKGNAMESUFFIX)
.include "Makefile.interface"
.else
USES+=		ncurses
CONFIGURE_ARGS+=--enable-interface=ncurses,vt100,server \
		--enable-network

CONFLICTS_INSTALL?=	timidity

DOCFILES=	README.alsaseq README.dl README.m2m README.mts README.sf

pre-patch:
	@${RM} ${WRKSRC}/libarc/*.h
	@${RM} ${WRKSRC}/utils/mblock.h

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TIMID_LIBDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/timidity
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man5

post-install:
	cd ${WRKSRC}/doc/${EUCJP_LOCALE} && \
		${INSTALL_MAN} timidity.1 ${STAGEDIR}${PREFIX}/share/man/ja/man1 && \
		${INSTALL_MAN} timidity.cfg.5 ${STAGEDIR}${PREFIX}/share/man/ja/man5
	cd ${STAGEDIR}${PREFIX}/share/man/ja/man1 && \
		${CAT} timidity.1 | \
			${ICONV_CMD} -f euc-jp -t utf-8 > timidity.1.utf-8 && \
		${MV} -f timidity.1.utf-8 timidity.1
	cd ${STAGEDIR}${PREFIX}/share/man/ja/man5 && \
		${CAT} timidity.cfg.5 | \
			${ICONV_CMD} -f euc-jp -t utf-8 > timidity.cfg.5.utf-8 && \
		${MV} -f timidity.cfg.5.utf-8 timidity.cfg.5
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/C && ${INSTALL_DATA} ${DOCFILES} \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME}
	(cd ${WRKSRC}/doc/${EUCJP_LOCALE} && ${INSTALL_DATA} ${DOCFILES} \
		${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME})
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/timidity

.endif # PKGNAMESUFFIX
.include <bsd.port.mk>

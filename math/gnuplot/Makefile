PORTNAME=	gnuplot
PORTVERSION=	5.4.10
PORTREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	SF

MAINTAINER=	glewis@FreeBSD.org
COMMENT?=	Command-line driven graphing utility
WWW=		http://www.gnuplot.info/

LICENSE=	Gnuplot
LICENSE_NAME=	Gnuplot license
LICENSE_FILE=	${WRKSRC}/Copyright
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CONFLICTS_INSTALL?=	gnuplot-lite

USES+=		compiler:c++11-lang cpe groff iconv localbase pkgconfig readline
CPE_VENDOR=	gnuplot_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-readline=gnu \
		--without-linux-vga \
		--without-lisp-files \
		--without-tutorial \
		--with-bitmap-terminals \
		--with-qt=no

.if defined(LITE)
CONFIGURE_ARGS+=--disable-x11-mbfonts \
		--disable-x11-external \
		--disable-wxwidgets \
		--without-x \
		--without-ggi \
		--without-gd \
		--without-caca \
		--without-wx \
		--without-gpic \
		--without-mif \
		--without-cairo \
		--without-lua \
		--without-latex \
		--without-kpsexpand
PLIST_SUB+=	X11="@comment "
.else
USES+=		gnome jpeg ncurses tex xorg
USE_TEX=	kpathsea
USE_GNOME+=	atk cairo gtk30 gdkpixbuf2
USE_WX=		3.2+
USE_XORG+=	x11
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libgd.so:graphics/gd \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libtiff.so:graphics/tiff
CONFIGURE_ARGS+=--with-gd=${LOCALBASE} \
		--with-gpic \
		--with-mif \
		--with-kpsexpand \
		--with-latex \
		ac_cv_prog_KPSEXPAND=${LOCALBASE}/bin/kpsexpand \
		ac_cv_prog_PLAINTEX=${LOCALBASE}/bin/tex \
		ac_cv_prog_LATEX=${LOCALBASE}/bin/latex \
		ac_cv_prog_PDFLATEX=${LOCALBASE}/bin/pdflatex
PLIST_SUB+=	X11=""
.endif

TEST_TARGET=	check
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES GRIDBOX LIBCERF LUA
GRIDBOX_DESC=		Use the gridbox optimization for hidden3d
LIBCERF_DESC=		User the libcerf

GRIDBOX_CONFIGURE_OFF=	--disable-h3d-quadtree --enable-h3d-gridbox
LIBCERF_CONFIGURE_WITH=		libcerf
LIBCERF_LIB_DEPENDS=	libcerf.so:math/libcerf
LUA_USES=	lua:flavors
LUA_CONFIGURE_WITH=		lua

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install:/s/install-am//' ${WRKSRC}/share/LaTeX/Makefile.in
	@${REINPLACE_CMD} -e \
		's|)/@PACKAGE@/@PKG_MAJOR@|)|g' ${WRKSRC}/src/Makefile.in

post-patch-LUA-on:
	@${REINPLACE_CMD} -e \
		's|lua5\.3|lua-${LUA_VER}|g;s|lua-53|lua-${LUA_VER_STR}|g;s|LUA=lua-${LUA_VER}|LUA=lua${LUA_VER_STR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|luaL_checkint(|(int)luaL_checkinteger(|' ${WRKSRC}/term/lua.trm

post-build-DOCS-on:
	@cd ${WRKSRC}/docs && ${MAKE} groff

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/5.4 ; \
		${INSTALL_DATA} ${WRKSRC}/share/gnuplotrc \
		${STAGEDIR}${DATADIR}/5.4/gnuplotrc.sample

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1
	cd ${WRKSRC}/share/man && \
		${INSTALL_MAN} ${PORTNAME}-ja_JP.UTF-8 \
			${STAGEDIR}${PREFIX}/share/man/ja/man1/${PORTNAME}.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/psdoc
	cd ${WRKSRC}/docs && ${INSTALL_DATA} gnuplot.txt gnuplot.dvi \
		gnuplot.ps ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/psdoc && ${INSTALL_DATA} README ps_* ${STAGEDIR}${DOCSDIR}/psdoc

.if defined(LITE)
post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${RMDIR} libexec/gnuplot/5.4 libexec/gnuplot
.endif

.include <bsd.port.mk>

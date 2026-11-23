PORTNAME=	stellarium
PORTVERSION=	26.3
CATEGORIES=	astro
MASTER_SITES=	https://github.com/Stellarium/stellarium/releases/download/v${PORTVERSION}/ \
		https://mirrors.tuna.tsinghua.edu.cn/github-release/Stellarium/stellarium/v${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:Nstars_*.cat:N*.pdf}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3D photo-realistic sky renderer (planetarium)
WWW=		https://stellarium.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/fast_float/fast_float.h:math/fast_float
LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libmd4c-html.so:textproc/md4c \
		libnlopt.so:math/nlopt@minimal

USES=		cmake compiler:c++17-lang desktop-file-utils \
		perl5 qt:6 shared-mime-info tar:xz
USE_PERL5=	build
USE_QT=		base charts positioning svg
CMAKE_ON=	ENABLE_QT6

PORTDOCS=	CREDITS.md ChangeLog README.md \
		stellarium_user_guide-${PORTVERSION}-1.pdf

OPTIONS_DEFINE=		DOCS GPS MORE_STARS MULTIMEDIA NLS SCRIPTS \
			SHOWMYSKY TELESCOPE TEST TEXTURES WEBENGINE XLSX
OPTIONS_DEFAULT=	GPS MULTIMEDIA SCRIPTS SHOWMYSKY TELESCOPE \
			WEBENGINE XLSX
OPTIONS_SUB=		yes

GPS_DESC=		GPS (NMEA handling) support
MORE_STARS_DESC=	Install additional star catalogs (4.8GB)
MULTIMEDIA_DESC=	Sound and video support
SCRIPTS_DESC=		Remote control and scripting support
SHOWMYSKY_DESC=		Realistic atmosphere light scattering
TELESCOPE_DESC=		Build telescope control plugin
TEXTURES_DESC=		Install better quality textures
WEBENGINE_DESC=		Get and show extra object information
XLSX_DESC=		Data export to Excel files support

DOCS_DISTFILES=		stellarium_user_guide-${PORTVERSION}-1.pdf

GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_USE=		QT=serialport
GPS_CMAKE_OFF=		-DENABLE_GPS:BOOL=OFF

MULTIMEDIA_USE=		QT=multimedia
MULTIMEDIA_CMAKE_OFF=	-DENABLE_MEDIA:BOOL=OFF

NLS_USE=		QT=tools:build
NLS_CMAKE_OFF=		-DENABLE_NLS:BOOL=OFF

SCRIPTS_USE=		QT=declarative
SCRIPTS_CMAKE_OFF=	-DENABLE_SCRIPTING:BOOL=OFF

SHOWMYSKY_BUILD_DEPENDS=	${LOCALBASE}/include/ShowMySky/AtmosphereRenderer.hpp:astro/calcmysky
SHOWMYSKY_CMAKE_OFF=	-DENABLE_SHOWMYSKY:BOOL=OFF

TELESCOPE_LIB_DEPENDS=	libindiclient.so:devel/indi
TELESCOPE_USE=		QT=serialport
TELESCOPE_CMAKE_OFF=	-DUSE_PLUGIN_TELESCOPECONTROL:BOOL=OFF

TEST_CMAKE_ON=		-DENABLE_TESTING:BOOL=ON

TEXTURES_MASTER_SITES=	SF/${PORTNAME}/Extra-data-files/textures:gfx
TEXTURES_DISTFILES=	textures-1K.zip:gfx

WEBENGINE_USE=		QT=declarative,webchannel,webengine
WEBENGINE_CMAKE_OFF=	-DENABLE_QTWEBENGINE:BOOL=OFF

XLSX_LIB_DEPENDS=	libQXlsxQt6.so:devel/qxlsx@qt6
XLSX_CMAKE_OFF=		-DENABLE_XLSX:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMORE_STARS}
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/stars-3.0:stars30
DISTFILES+=	stars_4_1v0_6.cat:stars30 stars_5_1v0_6.cat:stars30 \
		stars_6_1v0_4.cat:stars30 stars_7_1v0_4.cat:stars30 \
		stars_8_2v0_3.cat:stars30
.endif

post-extract-DOCS-on:
	@${LN} -sf ${_DISTDIR}/stellarium_user_guide-${PORTVERSION}-1.pdf \
		${WRKSRC}

post-install-MORE_STARS-on:
	${INSTALL_DATA} ${DISTDIR}/stars_4_1v0_6.cat \
		${DISTDIR}/stars_5_1v0_6.cat \
		${DISTDIR}/stars_6_1v0_4.cat \
		${DISTDIR}/stars_7_1v0_4.cat \
		${DISTDIR}/stars_8_2v0_3.cat \
		${STAGEDIR}${DATADIR}/stars/hip_gaia3

post-install-TEXTURES-on:
	(cd ${WRKDIR} && for f in *.png; do \
		case $$f in neb*|sun.png) continue ;; esac ; \
		new=`${STAT} -f '%z' $$f` ; \
		existing=`${STAT} -f '%z' \
			${STAGEDIR}${DATADIR}/textures/$$f` ; \
		${TEST} $$new -gt $$existing || continue ; \
		${ECHO_CMD} "-- Replacing texture: $$f\
			(has larger file size: $$new > $$existing)" ; \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/textures ; \
	done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test-TEST-on:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>

PORTNAME=	mozc
PORTVERSION=	2.30.5490.102
PORTREVISION?=	1
CATEGORIES=	japanese

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT?=	Mozc Japanese Input Method, Server
WWW=		https://github.com/google/mozc

PATCH_DEPENDS=${PYTHON_CMD}:${PYTHON_PORTSDIR}
BUILD_DEPENDS=	bazel:devel/bazel
RUN_DEPENDS=	xdg-open:devel/xdg-utils

DIST_SUBDIR=	${PORTNAME}

.include "Makefile.MASTER_SITES"

USES=	compiler:c++20-lang gmake localbase ninja:build pkgconfig \
	python:3.7+,build shebangfix tar:bzip2

USE_GITHUB=	yes
GH_TUPLE=	fcitx:mozc:e379550 \
		hiroyuki-komatsu:japanese-usage-dictionary:a4a6677:udic

BUILD_WRKSRC=	${WRKSRC}/src
BUILD_MOZC_CMD=	${SETENV} PATH="${PREFIX}/openjdk11/bin:${PATH}" \
		bazel --output_user_root=${WRKDIR}/bazel_out \
			build -c opt --copt=-fPIC --host_linkopt=-lm \
			--verbose_failures --sandbox_debug --config oss_linux \
			--distdir=${WRKDIR}/bazel-dist

BUILD_MOZC_LIST?=	mozc_server

.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-server

LICENSE=		BSD3CLAUSE NAISTL
LICENSE_COMB=		multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_BSD3CLAUSE=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_NAME_NAISTL=	Nara Institute of Science and Technology License
LICENSE_PERMS_NAISTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_NAISTL=	${WRKSRC}/src/data/dictionary_oss/README.txt
LICENSE_DISTFILES_NAISTL=${DISTNAME}${EXTRACT_SUFX}

OPTIONS_DEFINE=	UTDIC
OPTIONS_MULTI=	UTDIC
OPTIONS_MULTI_UTDIC=	ALTCANNADIC EDICT2 JAWIKI NEOLOGD PERSONALNAME \
		PLACENAME SKKJISYO SUDACHIDICT

ALTCANNADIC_DESC=	Dictionary from Alt-Cannadic
EDICT2_DESC=		Dictionary from EDICT2
JAWIKI_DESC=		Dictionary from Japanese Wikipedia
NEOLOGD_DESC=		Dictionary from NEologd
PERSONALNAME_DESC=	Personal Name Dictionary
PLACENAME_DESC=		Place Name Dictionary
SKKJISYO_DESC=		Dictionary from from SKK-JISYO
SUDACHIDICT_DESC=	Dictionary from SudachiDict
UTDIC_DESC=		Additional UT Dictionary

# GPLv2
ALTCANNADIC_GH_TUPLE=	utuhiro78:mozcdic-ut-alt-cannadic:9e71156:altcannadic

# CC-BY-SA-4.0
EDICT2_GH_TUPLE=	utuhiro78:mozcdic-ut-edict2:38f7f74:edict2
JAWIKI_GH_TUPLE=	utuhiro78:mozcdic-ut-jawiki:e9e2931:jawiki

# APACHE20
NEOLOGD_GH_TUPLE=	utuhiro78:mozcdic-ut-neologd:65370a0:neologd

# APACHE20
PERSONALNAME_GH_TUPLE=	utuhiro78:mozcdic-ut-personal-names:e104958:personal

# APCHE20
PLACENAME_GH_TUPLE=	utuhiro78:mozcdic-ut-place-names:1e45b1d:place

# APACHE20 GPLv2
SKKJISYO_GH_TUPLE=	utuhiro78:mozcdic-ut-skk-jisyo:e1f26b8:skkjisyo

# APACHE20
SUDACHIDICT_GH_TUPLE=	utuhiro78:mozcdic-ut-sudachidict:f25afb4:sudachi

# APACHE20 multi
UTDIC_GH_TUPLE=		utuhiro78:merge-ut-dictionaries:ea8cfbd:ut
UTDIC_IDDEF=		https://raw.githubusercontent.com/google/mozc/master/src/data/dictionary_oss/id.def
UTDIC_JAWIKI=		https://dumps.wikimedia.org/jawiki/latest/jawiki-latest-all-titles-in-ns0.gz
UTDIC_PATCH_DEPENDS=	rubygem-zlib>0:devel/rubygem-zlib
UTDIC_USES=		ruby:build

.elif ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
BUILD_DEPENDS+=	libglvnd>0:graphics/libglvnd
USES+=		qt:6
USE_LOCALE=	C.UTF-8
USE_QT=		base

.elif ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
USES+=		gettext-runtime gnome xorg
USE_XORG=	xcb
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

.elif ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
USES+=		emacs

.elif ${BUILD_MOZC_LIST:Mfcitx_mozc}
USES+=		gettext-tools

.elif ${BUILD_MOZC_LIST:Mfcitx5_mozc}
USES+=		gettext-tools

.endif

# Use GCC only when the stock clang does not have libc++.so.
.if exists(/usr/bin/clang) && exists(/usr/lib/libc++.so)
_CCTYPE=	clang
.else
USE_GCC=	yes
_CCTYPE=	gcc
.endif

.include <bsd.port.pre.mk>

post-extract:
	@${RMDIR} ${WRKSRC}/src/third_party/abseil-cpp && \
		${RLN} ${WRKDIR}/abseil-cpp-* ${WRKSRC}/src/third_party/abseil-cpp
	@${RMDIR} ${WRKSRC}/src/third_party/protobuf && \
		${RLN} ${WRKDIR}/protobuf-* ${WRKSRC}/src/third_party/protobuf
	@${MKDIR} ${WRKDIR}/bazel-dist
.for file in ${DISTFILES:C/\:(.*)//}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKDIR}/bazel-dist
.endfor

post-patch:
	@${CP} ${PATCHDIR}/bazelrc ${WRKDIR} && \
		${REINPLACE_CMD} -e 's@%%BAZEL_DIR%%@${WRKDIR}@g;s@%%BAZEL_DIST%%@${WRKDIR}@g;' \
			${WRKDIR}/bazelrc
	@${FIND} ${BUILD_WRKSRC} -type f \
		\( -name 'BUILD' -o -name '*.bzl' -o -name '*.cc' -o -name '*.h' \) \
		-exec ${REINPLACE_CMD} -E -e "s,'python','${PYTHON_CMD}',g;" \
			-e 's,/usr/bin/xdg-open,${PREFIX}/bin/xdg-open,g;' \
			-e 's,/usr/lib/mozc,${PREFIX}/libexec,g;' \
			-e 's,LINUX_MOZC_SERVER_DIR \+ "/documents","${DATADIR}",g;' \
			-e 's,/usr/lib/mozc/documents,${DATADIR},g;' \
			-e 's,/usr/share,${PREFIX}/share,g;' \
			-e 's,/usr/lib,${PREFIX}/lib,g;' \
			-e 's,OS=="linux",OS=="linux" or OS=="freebsd",g;' \
			-e 's,target_platform=="Linux",target_platform=="Linux" or target_platform=="FreeBSD",g;' \
			-e 's,defined\(__linux__\),defined(__linux__) || defined(__FreeBSD__),g;' \
			-e 's,^#ifdef __linux__$$,#if defined(__linux__) || defined(__FreeBSD__),;' \
			-e 's,^#ifdef __linux$$,#if defined(__linux__) || defined(__FreeBSD__),;' \
			-e 's,ByteSize\(,ByteSizeLong\(,g;' {} \;
	@${REINPLACE_CMD} 's@path = "/usr"@path = "${PREFIX}"@g' \
		${BUILD_WRKSRC}/WORKSPACE.bazel

.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
	${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
		${BUILD_WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh
	${REINPLACE_CMD} \
		's,IconName=.*,IconName=${LOCALBASE:Q}/share/fcitx/mozc/icon/mozc.png,' \
			${BUILD_WRKSRC}/unix/fcitx/mozc.conf
.endif

.if ${BUILD_MOZC_LIST:Mfcitx5_mozc} == "fcitx5_mozc"
	${CP} ${BUILD_WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh ${BUILD_WRKSRC}/unix/fcitx5/
	${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
	    ${BUILD_WRKSRC}/unix/fcitx5/gen_fcitx_mozc_i18n.sh
#	${REINPLACE_CMD} 's@^    linkopts@    srcs = glob(["lib/libFcitx5*.so"]),\n    linkopts@g' \
#		${BUILD_WRKSRC}/BUILD.fcitx5.bazel
.endif

.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
	${REINPLACE_CMD} 's@"Qt5Widgets"],@"Qt5Widgets"],\n  includedirs = ["${PREFIX}/include"],\n  symlinks = ["${PREFIX}/include/GL"],@' ${BUILD_WRKSRC}/WORKSPACE.bazel
.endif

#################################################
# mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server" || make(makesum)

.if ${PORT_OPTIONS:MNEOLOGD} || ${PORT_OPTIONS:MPERSONALNAME} || \
	${PORT_OPTIONS:MPLACENAME}
LICENSE+=	APACHE20
.endif
.if ${PORT_OPTIONS:MEDICT2} || ${PORT_OPTIONS:MJAWIKI}
LICENSE+=	CC-BY-SA-4.0
.endif
.if ${PORT_OPTIONS:MALTCANNADIC} || ${PORT_OPTIONS:MSKKJISYO}
LICENSE+=	GPLv2
.endif

MASTER_SITES+=	https://www.post.japanpost.jp/zipcode/dl/kogaki/zip/:kenall \
		https://www.post.japanpost.jp/zipcode/dl/jigyosyo/zip/:jigyosyo
DISTFILES+=	ken_all.zip:kenall \
		jigyosyo.zip:jigyosyo
PLIST_FILES+=	bin/mozc \
		libexec/mozc_server
SUB_FILES+=	mozc

post-extract-mozc_server:
.if ${PORT_OPTIONS:MUTDIC}
	@${ECHO_MSG} "Downloading files required by UT Dictionary..."
	@cd ${WRKDIR}/merge-ut-dictionaries-*/src && \
		${FETCH_CMD} ${UTDIC_JAWIKI} && \
		${FETCH_CMD} ${UTDIC_IDDEF}
.endif

post-patch-mozc_server:
.for file in ${DISTFILES:M*\:kenall:S/:kenall//} ${DISTFILES:M*\:jigyosyo:S/:jigyosyo//}
		@${UNZIP_NATIVE_CMD} -q -L -d ${BUILD_WRKSRC}/data/dictionary_oss \
			${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor
	@cd ${BUILD_WRKSRC}/data/dictionary_oss && \
		${SETENV} PYTHONPATH=${BUILD_WRKSRC} \
			${PYTHON_CMD} ${BUILD_WRKSRC}/dictionary/gen_zip_code_seed.py \
				--zip_code=ken_all.csv --jigyosyo=jigyosyo.csv >> dictionary09.txt
	@${MV} ${WRKSRC_udic}/usage_dict.txt \
		${BUILD_WRKSRC}/third_party/japanese_usage_dictionary
.if ${PORT_OPTIONS:MUTDIC}
	# ut dictionary
	@${REINPLACE_CMD} -e 's@coding:@en&@g;' \
		-e 's@`wget @#&@;' -e "s@^require 'nkf'@#&@;" \
		-e "s@^require 'open-uri'@#&@;" \
		-e 's@^url = "https://raw.githubusercontent.com/google/mozc/master/src/data/dictionary_oss/id.def"@id_def = File.new("id.def", "r")@;' \
		-e 's@^id_mozc = URI.open(url)@id_mozc = id_def@;' \
			${WRKDIR}/merge-ut-dictionaries-*/src/*.rb
	cd ${WRKDIR}/merge-ut-dictionaries-*/src && \
		${CP} ../../mozcdic-ut-*/mozcdic-ut-*.txt.tar.bz2 . && \
		for f in mozcdic-ut-*.txt.tar.bz2; do ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} $$f ${EXTRACT_AFTER_ARGS}; done && \
		${CAT} *.txt > ${WRKDIR}/mozcdic-ut.txt && \
		${MV} ${WRKDIR}/mozcdic-ut.txt . && \
		${RUBY} -W2 -Ku remove_duplicate_ut_entries.rb mozcdic-ut.txt && \
		${RUBY} -W2 -Ku count_word_hits.rb && \
		${RUBY} -W2 -Ku apply_word_hits.rb mozcdic-ut.txt && \
		${CAT} mozcdic-ut.txt \
			>> ${BUILD_WRKSRC}/data/dictionary_oss/dictionary00.txt
.endif

post-extract: post-extract-mozc_server

post-patch: post-patch-mozc_server

do-build-mozc_server:
	cd ${BUILD_WRKSRC} && \
		${BUILD_MOZC_CMD} server:mozc_server

do-install-mozc_server:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/bazel-bin/server/mozc_server \
	    ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/mozc ${STAGEDIR}/${PREFIX}/bin
.endif
#################################################

#################################################
# mozc_tool
.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"

PLIST_FILES+=	libexec/mozc_tool \
		bin/mozc_tool \
		%%DATADIR%%/credits_en.html \
		%%DATADIR%%/icons/product_logo.png \
		%%DATADIR%%/icons/update_uptodate.png

SUB_FILES+=	mozc_tool

do-build-mozc_tool:
	cd ${BUILD_WRKSRC} && \
		${BUILD_MOZC_CMD} gui/tool:mozc_tool

do-install-mozc_tool:
	${INSTALL_PROGRAM} \
		${BUILD_WRKSRC}/bazel-out/freebsd-opt/bin/gui/tool/mozc_tool \
			${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/mozc_tool ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
			${STAGEDIR}${DATADIR}/icons/product_logo.png
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
			${STAGEDIR}${DATADIR}/icons/update_uptodate.png
	${INSTALL_DATA} ${BUILD_WRKSRC}/data/installer/credits_en.html \
		${STAGEDIR}${DATADIR}
.endif
#################################################

#################################################
# ibus_mozc
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"

LIB_DEPENDS+=	libibus-1.0.so:textproc/ibus
RUN_DEPENDS+=	mozc:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	libexec/mozc_renderer \
		libexec/ibus-engine-mozc \
		%%DATADIR%%/icons/alpha_full.png \
		%%DATADIR%%/icons/alpha_half.png \
		%%DATADIR%%/icons/dictionary.png \
		%%DATADIR%%/icons/direct.png \
		%%DATADIR%%/icons/hiragana.png \
		%%DATADIR%%/icons/katakana_full.png \
		%%DATADIR%%/icons/katakana_half.png \
		%%DATADIR%%/icons/product_icon.png \
		%%DATADIR%%/icons/properties.png \
		%%DATADIR%%/icons/tool.png \
		share/ibus/component/mozc.xml
PLIST_DIRS+=	%%DATADIR%%/icons ${DATADIR_REL}

do-build-ibus_mozc:
	cd ${BUILD_WRKSRC} && \
		${BUILD_MOZC_CMD} unix/ibus:ibus

do-install-ibus_mozc:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/mozc_renderer \
	    ${STAGEDIR}${PREFIX}/libexec/mozc_renderer
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/ibus_mozc \
	    ${STAGEDIR}${PREFIX}/libexec/ibus-engine-mozc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ibus/component
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/gen/unix/ibus/mozc.xml \
	    ${STAGEDIR}${PREFIX}/share/ibus/component/mozc.xml
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/${F}.png \
	    ${STAGEDIR}${DATADIR}/icons/${F:S/^ui-//}.png
.endfor
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
	    ${STAGEDIR}${DATADIR}/icons/product_icon.png
.endif
#################################################

#################################################
# uim_mozc
.if ${BUILD_MOZC_LIST:Muim_mozc} == "uim_mozc" || make(makesum)
GH_TUPLE+=	e-kato:macuim:v0.6.16.2.1:MU

LIB_DEPENDS+=	libuim.so:textproc/uim
RUN_DEPENDS+=	mozc:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-unix-uim-mozc.cc \
		${PATCHDIR}/extra-patch-src-unix-uim-key_translator.h \
		${PATCHDIR}/extra-patch-src-unix-uim-key_translator.cc
#		${PATCHDIR}/extra-patch-src-unix-uim-uim.gyp \

PLIST_FILES+=	lib/uim/plugin/libuim-mozc.so \
		%%DATADIR%%/mozc.scm \
		%%DATADIR%%/mozc-custom.scm \
		%%DATADIR%%/mozc-key-custom.scm \
		%%DATADIR%%/pixmaps/mozc.png \
		"@postexec ${SETENV} MOZC_NOLOG=true ${LOCALBASE}/bin/uim-module-manager --register mozc" \
		"@preunexec ${LOCALBASE}/bin/uim-module-manager --unregister mozc"

post-extract-uim_mozc:
	${MV} ${WRKSRC_MU}/Mozc/uim ${BUILD_WRKSRC}/unix
	${REINPLACE_CMD} -e "s,/usr/lib/mozc,${LOCALBASE}/libexec," \
	    ${WRKSRC_MU}/Mozc/scm/mozc-custom.scm

post-extract: post-extract-uim_mozc

do-build-uim_mozc:

do-install-uim_mozc:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${INSTALL_LIB} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/libuim-mozc.so \
	    ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC_MU}/Mozc/scm && \
	    ${INSTALL_DATA} mozc.scm mozc-custom.scm mozc-key-custom.scm \
	    ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/pixmaps
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/product_icon_32bpp-128.png \
	    ${STAGEDIR}${DATADIR}/pixmaps/mozc.png
.endif
#################################################

#################################################
# fcitx_mozc
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"

LIB_DEPENDS+=	libfcitx-core.so:chinese/fcitx
RUN_DEPENDS+=	mozc:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	lib/fcitx/fcitx-mozc.so \
		share/fcitx/addon/fcitx-mozc.conf \
		share/fcitx/inputmethod/mozc.conf \
		%%DATADIR%%/icon/mozc.png \
		%%DATADIR%%/icon/mozc-alpha_full.png \
		%%DATADIR%%/icon/mozc-alpha_half.png \
		%%DATADIR%%/icon/mozc-direct.png \
		%%DATADIR%%/icon/mozc-hiragana.png \
		%%DATADIR%%/icon/mozc-katakana_full.png \
		%%DATADIR%%/icon/mozc-katakana_half.png \
		%%DATADIR%%/icon/mozc-dictionary.png \
		%%DATADIR%%/icon/mozc-properties.png \
		%%DATADIR%%/icon/mozc-tool.png \
		share/locale/ja/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_CN/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_TW/LC_MESSAGES/fcitx-mozc.mo
PLIST_DIRS+=	%%DATADIR%%/icon ${DATADIR_REL}

do-build-fcitx_mozc:

do-install-fcitx_mozc:
	@${MKDIR} \
	    ${STAGEDIR}${PREFIX}/lib/fcitx \
	    ${STAGEDIR}${PREFIX}/share/fcitx/addon \
	    ${STAGEDIR}${PREFIX}/share/fcitx/inputmethod
	${INSTALL_LIB} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/fcitx-mozc.so \
	    ${STAGEDIR}${PREFIX}/lib/fcitx/fcitx-mozc.so
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx/fcitx-mozc.conf \
	    ${STAGEDIR}${PREFIX}/share/fcitx/addon/fcitx-mozc.conf
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx/mozc.conf \
	    ${STAGEDIR}${PREFIX}/share/fcitx/inputmethod/mozc.conf
	@${MKDIR} ${STAGEDIR}${DATADIR}/icon
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/${F}.png \
	    ${STAGEDIR}${DATADIR}/icon/${F:S,^ui-,mozc-,}.png
.endfor
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/product_icon_32bpp-128.png \
	    ${STAGEDIR}${DATADIR}/icon/mozc.png
.for L in ja zh_CN zh_TW
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/gen/unix/fcitx/po/${L}.mo \
	    ${STAGEDIR}${PREFIX}/share/locale/${L}/LC_MESSAGES/fcitx-mozc.mo
.endfor
.endif #fcitx_mozc
#################################################

#################################################
# fcitx5_mozc
.if ${BUILD_MOZC_LIST:Mfcitx5_mozc} == "fcitx5_mozc"

LIB_DEPENDS+=	libFcitx5Core.so:textproc/fcitx5
RUN_DEPENDS+=	mozc:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	lib/fcitx5/fcitx5-mozc.so \
		share/fcitx5/addon/mozc.conf \
		share/fcitx5/inputmethod/mozc.conf \
		share/icons/hicolor/128x128/apps/fcitx_mozc.png \
		share/icons/hicolor/32x32/apps/fcitx_mozc.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_alpha_full.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_alpha_half.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_direct.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_hiragana.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_katakana_full.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_katakana_half.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_dictionary.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_properties.png \
		share/icons/hicolor/48x48/apps/fcitx_mozc_tool.png \
		share/locale/ca/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/da/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/de/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/he/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/ja/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/ko/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/ru/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/tr/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/zh_CN/LC_MESSAGES/fcitx5-mozc.mo \
		share/locale/zh_TW/LC_MESSAGES/fcitx5-mozc.mo \
		share/metainfo/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml

do-build-fcitx5_mozc:
	cd ${BUILD_WRKSRC} && \
		${BUILD_MOZC_CMD} unix/fcitx5:fcitx5-mozc.so unix:icons; \
		msgfmt --xml -d unix/fcitx5/po/ \
			--template unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml.in \
			-o unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml
	cd ${BUILD_WRKSRC}/unix/fcitx5 && ${SH} gen_fcitx_mozc_i18n.sh ./po

do-install-fcitx5_mozc:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/fcitx5 \
		${STAGEDIR}${PREFIX}/share/fcitx5/addon \
		${STAGEDIR}${PREFIX}/share/fcitx5/inputmethod \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_PROGRAM} \
		${BUILD_WRKSRC}/bazel-out/freebsd-opt/bin/unix/fcitx5/fcitx5-mozc.so \
			${STAGEDIR}${PREFIX}/lib/fcitx5
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/unix/fcitx5/mozc-addon.conf \
			${STAGEDIR}${PREFIX}/share/fcitx5/addon/mozc.conf
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/unix/fcitx5/mozc.conf \
			${STAGEDIR}${PREFIX}/share/fcitx5/inputmethod/mozc.conf
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/data/images/product_icon_32bpp-128.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/fcitx_mozc.png
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/fcitx_mozc.png
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/../scripts/icons/${F}.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${F:S,^ui-,fcitx_mozc_,}.png
.endfor
	cd ${BUILD_WRKSRC} && \
		for mofile in unix/fcitx5/po/*.mo; do \
			locale=$${mofile##*/}; \
			locale=$${locale%.mo}; \
			${INSTALL_DATA} ${BUILD_WRKSRC}/$${mofile} \
				${STAGEDIR}${PREFIX}/share/locale/$${locale}/LC_MESSAGES/fcitx5-mozc.mo; \
		done
	${INSTALL_DATA} \
		${BUILD_WRKSRC}/unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml \
			${STAGEDIR}${PREFIX}/share/metainfo
.endif #fcitx5_mozc
#################################################

#################################################
# mozc_el
.if ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"

CATEGORIES+=	elisp
RUN_DEPENDS+=	mozc:japanese/mozc-server

NO_ARCH=	yes
PLIST_FILES+=	${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.elc \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.el.gz \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/leim-list.el
PLIST_DIRS+=	${EMACS_VERSION_SITE_LISPDIR}/mozc

post-patch-mozc_el:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.el

post-patch: post-patch-mozc_el

do-build-mozc_el:
	cd ${BUILD_WRKSRC}/unix/emacs && \
	    ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
	    -f batch-byte-compile mozc.el && \
	    ${GZIP_CMD} mozc.el

do-install-mozc_el:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.el.gz \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.elc \
	    ${FILESDIR}/leim-list.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/
.endif
#################################################

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

post-install:
	cd ${BUILD_WRKSRC} && bazel ${BAZEL_OPTS} shutdown

.include <bsd.port.post.mk>

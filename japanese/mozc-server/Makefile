PORTNAME=	mozc
PORTVERSION=	2.30.5618.102
PORTREVISION=	13
CATEGORIES=	japanese

DIST_SUBDIR=	${PORTNAME}
.include "Makefile.MASTER_SITES"

EXTRACT_ONLY=	${_DISTFILES:C@^([0-9]|apple|bazel|include|jawiki|platforms|pybind|re2|rules|stardoc|zlib).*@@}

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT?=	Mozc Japanese Input Method, Server
WWW=		https://github.com/google/mozc

LICENSE=		BSD3CLAUSE NAISTL
LICENSE_COMB=		multi
LICENSE_NAME_NAISTL=	Nara Institute of Science and Technology License
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_NAISTL=	${WRKSRC}/src/data/dictionary_oss/README.txt
LICENSE_PERMS_NAISTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_DISTFILES_BSD3CLAUSE=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_NAISTL=	${DISTNAME}${EXTRACT_SUFX}

FETCH_DEPENDS=	git:devel/git
PATCH_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
BUILD_DEPENDS=	bazel:devel/bazel7 \
		python3:lang/python3
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=	compiler:c++20-lang gmake localbase ninja:build pkgconfig \
	python:3.8+,build shebangfix tar:bzip2

USE_GITHUB=	yes
GH_TUPLE=	fcitx:mozc:08e3c4b
GH_TUPLE+=	abseil:abseil-cpp:4447c75:abseil/src/third_party/abseil-cpp
GH_TUPLE+=	google:googletest:b514bdc:googletest/src/third_party/gtest
GH_TUPLE+=	protocolbuffers:protobuf:7cc670c:protobuf/src/third_party/protobuf

USE_JAVA=	yes
JAVA_VERSION=	21
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes

BUILD_MOZC_LIST?=	mozc_server

BUILD_MOZC_CMD=	bazel ${BAZEL_BOOT} --server_javabase=${JAVA_HOME} \
		build ${BAZEL_ENV} ${BAZEL_COMMON_OPTS} \
		-c opt --copt=-fPIC --host_linkopt=-lm \
		--verbose_failures --sandbox_debug \
		--tool_java_language_version=${JAVA_VERSION} \
		--config oss_linux

BAZEL_BCR_LOCAL=	${DISTDIR}/bazel-central-registry
BAZEL_BCR_URL=	https://github.com/bazelbuild/bazel-central-registry.git

BAZEL_BOOT=	--output_base=${WRKDIR}/bazel-out-base \
		--output_user_root=${WRKDIR}/bazel-out-user

BAZEL_COMMON_OPTS=	--distdir=${DISTDIR}/${DIST_SUBDIR} \
		--registry="file://${BAZEL_BCR_LOCAL}"

BAZEL_ENV=	--action_env=PATH=${JAVA_HOME}/bin:${PATH}

BAZEL_WRKSRC=	${WRKSRC}/src

.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"

PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-server

# zip code
MASTER_SITES+=	https://www.post.japanpost.jp/zipcode/dl/kogaki/zip/:kenall \
		https://www.post.japanpost.jp/zipcode/dl/jigyosyo/zip/:jigyosyo
DISTFILES+=	ken_all.zip:kenall \
		jigyosyo.zip:jigyosyo
# usage dictionary
GH_TUPLE+=	hiroyuki-komatsu:japanese-usage-dictionary:a4a6677:udic/src/third_party/japanese_usage_dictionary

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
ALTCANNADIC_GH_TUPLE=	utuhiro78:mozcdic-ut-alt-cannadic:bf26bcb:altcannadic

# CC-BY-SA-4.0
EDICT2_GH_TUPLE=	utuhiro78:mozcdic-ut-edict2:33b4d09:edict2
JAWIKI_GH_TUPLE=	utuhiro78:mozcdic-ut-jawiki:9c0e66c:jawiki

# APACHE20
NEOLOGD_GH_TUPLE=	utuhiro78:mozcdic-ut-neologd:5a275dc:neologd

# APACHE20
PERSONALNAME_GH_TUPLE=	utuhiro78:mozcdic-ut-personal-names:ea85549:personal

# APCHE20
PLACENAME_GH_TUPLE=	utuhiro78:mozcdic-ut-place-names:d189fce:place

# APACHE20 GPLv2
SKKJISYO_GH_TUPLE=	utuhiro78:mozcdic-ut-skk-jisyo:c52cdb1:skkjisyo

# APACHE20
SUDACHIDICT_GH_TUPLE=	utuhiro78:mozcdic-ut-sudachidict:d12da3c:sudachi

# APACHE20 multi
UTDIC_GH_TUPLE=		utuhiro78:merge-ut-dictionaries:4d59023:ut
UTDIC_MASTER_SITES=	https://dumps.wikimedia.org/jawiki/latest/:title
UTDIC_DISTFILES=	jawiki-latest-all-titles-in-ns0.gz:title

.elif ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"

BUILD_DEPENDS+=	libglvnd>0:graphics/libglvnd
USES+=		qt:6
USE_LOCALE=	C.UTF-8
USE_QT=		base

.elif ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"

BUILD_DEPENDS+=	libglvnd>0:graphics/libglvnd
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES+=		gettext-runtime gnome xorg
USE_XORG=	xcb
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20

USES+=		qt:6
USE_LOCALE=	C.UTF-8
USE_QT=		base

.elif ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"

USES+=		emacs:noflavors

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
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
	@${CP} -a ${WRKDIR}/*.CSV ${BAZEL_WRKSRC}/third_party
.endif

post-patch:
	@${FIND} ${BAZEL_WRKSRC} -type f -not -path '*/third_party/*' \
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

.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
	${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
		${BAZEL_WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh
	${REINPLACE_CMD} \
		's,IconName=.*,IconName=${LOCALBASE:Q}/share/fcitx/mozc/icon/mozc.png,' \
		${BAZEL_WRKSRC}/unix/fcitx/mozc.conf
.endif

.if ${BUILD_MOZC_LIST:Mfcitx5_mozc} == "fcitx5_mozc"
	@${CP} ${BAZEL_WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh ${BAZEL_WRKSRC}/unix/fcitx5/
	@${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
		${BAZEL_WRKSRC}/unix/fcitx5/gen_fcitx_mozc_i18n.sh
.endif

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

PLIST_FILES+=	bin/mozc \
		libexec/mozc_server
SUB_FILES+=	mozc

post-patch-mozc_server:
.if ${PORT_OPTIONS:MUTDIC}
	@${ECHO_MSG} "===> Creating mozcdic-ut.txt for UT Dictionary. It takes a long time!"
	cd ${WRKSRC_ut}/src/merge && \
		${PATCH} < ${PATCHDIR}/extra-patch-merge_dictionaries.py && \
		${CP} ${BAZEL_WRKSRC}/data/dictionary_oss/id.def . && \
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${UTDIC_DISTFILES:M*\:title:C@\:title@@} . && \
		${BZCAT} ../../../mozcdic-ut-*/mozcdic-ut-*.txt.bz2 > mozcdic-ut.txt && \
		${PYTHON_CMD} merge_dictionaries.py mozcdic-ut.txt && \
		${CAT} mozcdic-ut.txt \
			>> ${BAZEL_WRKSRC}/data/dictionary_oss/dictionary00.txt
.endif

post-patch: post-patch-mozc_server

do-build-mozc_server:
	cd ${BAZEL_WRKSRC} && \
		${BUILD_MOZC_CMD} //server:mozc_server

do-install-mozc_server:
	${INSTALL_PROGRAM} \
		${BAZEL_WRKSRC}/bazel-bin/server/mozc_server \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} \
		${WRKDIR}/mozc ${STAGEDIR}/${PREFIX}/bin
.endif

.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"

PLIST_FILES+=	libexec/mozc_tool \
		bin/mozc_tool \
		%%DATADIR%%/credits_en.html \
		%%DATADIR%%/icons/product_logo.png \
		%%DATADIR%%/icons/update_uptodate.png

SUB_FILES+=	mozc_tool

do-build-mozc_tool:
	cd ${BAZEL_WRKSRC} && \
		${BUILD_MOZC_CMD} //gui/tool:mozc_tool

do-install-mozc_tool:
	${INSTALL_PROGRAM} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/gui/tool/mozc_tool \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/mozc_tool ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${STAGEDIR}${DATADIR}/icons/product_logo.png
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${STAGEDIR}${DATADIR}/icons/update_uptodate.png
	${INSTALL_DATA} ${BAZEL_WRKSRC}/data/installer/credits_en.html \
		${STAGEDIR}${DATADIR}
.endif

.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"

LIB_DEPENDS+=	libibus-1.0.so:textproc/ibus
RUN_DEPENDS+=	mozc:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	libexec/mozc_renderer \
		libexec/ibus-engine-mozc \
		%%DATADIR%%/alpha_full.png \
		%%DATADIR%%/alpha_half.png \
		%%DATADIR%%/dictionary.png \
		%%DATADIR%%/direct.png \
		%%DATADIR%%/hiragana.png \
		%%DATADIR%%/katakana_full.png \
		%%DATADIR%%/katakana_half.png \
		%%DATADIR%%/product_icon.png \
		%%DATADIR%%/properties.png \
		%%DATADIR%%/tool.png \
		share/ibus/component/mozc.xml
PLIST_DIRS+=	${DATADIR_REL}

post-patch-ibus_mozc:
	${REINPLACE_CMD} -e 's@ ulong @ unsigned long @;' \
		-e 's@ulong id@unsigned long id@;' -e 's@, ulong>@, unsigned long>@;' \
		${BAZEL_WRKSRC}/unix/ibus/ibus_wrapper.*

post-patch: post-patch-ibus_mozc

do-build-ibus_mozc:
	cd ${BAZEL_WRKSRC} && \
		${BUILD_MOZC_CMD} //unix/ibus:ibus_mozc \
			//unix/ibus:gen_mozc_xml \
			//renderer/qt:mozc_renderer

do-install-ibus_mozc:
	${INSTALL_PROGRAM} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/renderer/qt/mozc_renderer \
		${STAGEDIR}${PREFIX}/libexec/mozc_renderer
	${INSTALL_PROGRAM} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/unix/ibus/ibus_mozc \
		${STAGEDIR}${PREFIX}/libexec/ibus-engine-mozc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ibus/component
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/unix/ibus/mozc.xml \
		${STAGEDIR}${PREFIX}/share/ibus/component/mozc.xml
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/${F}.png \
		${STAGEDIR}${DATADIR}/${F:S/^ui-//}.png
.endfor
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${STAGEDIR}${DATADIR}/product_icon.png
.endif

.if ${BUILD_MOZC_LIST:Muim_mozc} == "uim_mozc" || make(makesum)

LICENSE_FILE+=	${BAZEL_WRKSRC}/src/unix/uim/LICENSE

GH_TUPLE+=	e-kato:macuim:7beac7b:MU

# These patches are from https://github.com/femshima/uim-mozc
# Modified to support the latest mozc.
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_MODULE.bazel \
		${PATCHDIR}/extra-patch-src_unix_uim_BUILD.bazel \
		${PATCHDIR}/extra-patch-src_unix_uim_key__translator.cc \
		${PATCHDIR}/extra-patch-src_unix_uim_key__translator.h \
		${PATCHDIR}/extra-patch-src_unix_uim_mozc.cc

LIB_DEPENDS+=	libuim.so:textproc/uim
RUN_DEPENDS+=	mozc:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	lib/uim/plugin/libuim-mozc.so \
		%%DATADIR%%/mozc.scm \
		%%DATADIR%%/mozc-custom.scm \
		%%DATADIR%%/mozc-key-custom.scm \
		%%DATADIR%%/pixmaps/mozc.png \
		%%DATADIR%%/pixmaps/mozc_tool_config_dialog.png \
		%%DATADIR%%/pixmaps/mozc_tool_dictionary_tool.png \
		%%DATADIR%%/pixmaps/mozc_tool_selector.png \
		"@postexec ${SETENV} MOZC_NOLOG=true ${LOCALBASE}/bin/uim-module-manager --register mozc" \
		"@preunexec ${LOCALBASE}/bin/uim-module-manager --unregister mozc"

post-extract-uim_mozc:
	${CP} -a ${WRKSRC_MU}/Mozc/uim ${BAZEL_WRKSRC}/unix

post-extract: post-extract-uim_mozc

post-patch-uim_mozc:
	${REINPLACE_CMD} -e "s,/usr/lib/mozc,${LOCALBASE}/libexec," \
		${WRKSRC_MU}/Mozc/scm/mozc-custom.scm
	${HEAD} --lines 32 ${BAZEL_WRKSRC}/unix/uim/mozc.cc > ${BAZEL_WRKSRC}/unix/uim/LICENSE

post-patch: post-patch-uim_mozc

do-build-uim_mozc:
	cd ${BAZEL_WRKSRC}&& \
		${BUILD_MOZC_CMD} //unix/uim:uim-mozc

do-install-uim_mozc:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${INSTALL_LIB} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/unix/uim/libuim-mozc.so \
		${STAGEDIR}${PREFIX}/lib/uim/plugin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC_MU}/Mozc/scm && \
		${INSTALL_DATA} mozc.scm mozc-custom.scm mozc-key-custom.scm \
		${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/pixmaps
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/product_icon_32bpp-128.png \
		${STAGEDIR}${DATADIR}/pixmaps/mozc.png
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ui-properties.png \
		${STAGEDIR}${DATADIR}/pixmaps/mozc_tool_config_dialog.png
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ui-dictionary.png \
		${STAGEDIR}${DATADIR}/pixmaps/mozc_tool_dictionary_tool.png
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ui-tool.png \
		${STAGEDIR}${DATADIR}/pixmaps/mozc_tool_selector.png
.endif

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
		share/locale/ca/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/da/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/de/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/ja/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/ko/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/ru/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_CN/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_TW/LC_MESSAGES/fcitx-mozc.mo
PLIST_DIRS+=	%%DATADIR%%/icon ${DATADIR_REL}

do-build-fcitx_mozc:
	cd ${BAZEL_WRKSRC} && \
		${BUILD_MOZC_CMD} //unix/fcitx:fcitx-mozc.so
	cd ${BAZEL_WRKSRC}/unix/fcitx && ${SH} gen_fcitx_mozc_i18n.sh ./po

do-install-fcitx_mozc:
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/fcitx \
		${STAGEDIR}${PREFIX}/share/fcitx/addon \
		${STAGEDIR}${PREFIX}/share/fcitx/inputmethod
	${INSTALL_LIB} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/unix/fcitx/fcitx-mozc.so \
		${STAGEDIR}${PREFIX}/lib/fcitx/fcitx-mozc.so
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/unix/fcitx/fcitx-mozc.conf \
		${STAGEDIR}${PREFIX}/share/fcitx/addon/fcitx-mozc.conf
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/unix/fcitx/mozc.conf \
		${STAGEDIR}${PREFIX}/share/fcitx/inputmethod/mozc.conf
	@${MKDIR} ${STAGEDIR}${DATADIR}/icon
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/${F}.png \
		${STAGEDIR}${DATADIR}/icon/${F:S,^ui-,mozc-,}.png
.endfor
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/product_icon_32bpp-128.png \
		${STAGEDIR}${DATADIR}/icon/mozc.png
	cd ${BAZEL_WRKSRC} && \
		for mofile in unix/fcitx/po/*.mo; do \
			locale=$${mofile##*/}; \
			locale=$${locale%.mo}; \
			${INSTALL_DATA} ${BAZEL_WRKSRC}/$${mofile} \
				${STAGEDIR}${PREFIX}/share/locale/$${locale}/LC_MESSAGES/fcitx-mozc.mo; \
		done

.endif #fcitx_mozc

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
	cd ${BAZEL_WRKSRC} && \
		${BUILD_MOZC_CMD} //unix/fcitx5:fcitx5-mozc.so; \
		msgfmt --xml -d unix/fcitx5/po/ \
			--template unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml.in \
			-o unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml
	cd ${BAZEL_WRKSRC}/unix/fcitx5 && ${SH} gen_fcitx_mozc_i18n.sh ./po

do-install-fcitx5_mozc:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/fcitx5 \
		${STAGEDIR}${PREFIX}/share/fcitx5/addon \
		${STAGEDIR}${PREFIX}/share/fcitx5/inputmethod \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_PROGRAM} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/unix/fcitx5/fcitx5-mozc.so \
			${STAGEDIR}${PREFIX}/lib/fcitx5
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/unix/fcitx5/mozc-addon.conf \
			${STAGEDIR}${PREFIX}/share/fcitx5/addon/mozc.conf
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/unix/fcitx5/mozc.conf \
			${STAGEDIR}${PREFIX}/share/fcitx5/inputmethod/mozc.conf
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/product_icon_32bpp-128.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/fcitx_mozc.png
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/fcitx_mozc.png
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/../scripts/icons/${F}.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${F:S,^ui-,fcitx_mozc_,}.png
.endfor
	cd ${BAZEL_WRKSRC} && \
		for mofile in unix/fcitx5/po/*.mo; do \
			locale=$${mofile##*/}; \
			locale=$${locale%.mo}; \
			${INSTALL_DATA} ${BAZEL_WRKSRC}/$${mofile} \
				${STAGEDIR}${PREFIX}/share/locale/$${locale}/LC_MESSAGES/fcitx5-mozc.mo; \
		done
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml \
			${STAGEDIR}${PREFIX}/share/metainfo
.endif #fcitx5_mozc

.if ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"

CATEGORIES+=	elisp
RUN_DEPENDS+=	mozc:japanese/mozc-server

NO_ARCH=	yes
PLIST_FILES+=	${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.elc \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.el.gz \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/leim-list.el \
		libexec/mozc_emacs_helper
PLIST_DIRS+=	${EMACS_VERSION_SITE_LISPDIR}/mozc

post-patch-mozc_el:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," \
		${BAZEL_WRKSRC}/unix/emacs/mozc.el

post-patch: post-patch-mozc_el

do-build-mozc_el:
	cd ${BAZEL_WRKSRC} && \
		${BUILD_MOZC_CMD} //unix/emacs:mozc_emacs_helper
	cd ${BAZEL_WRKSRC}/unix/emacs && \
		${EMACS_CMD} -batch -q -no-site-file -no-init-file \
			-f batch-byte-compile mozc.el && \
		${GZIP_CMD} mozc.el

do-install-mozc_el:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc
	${INSTALL_PROGRAM} \
		${BAZEL_WRKSRC}/bazel-out/freebsd-opt/bin/unix/emacs/mozc_emacs_helper \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} \
		${BAZEL_WRKSRC}/unix/emacs/mozc.el.gz \
		${BAZEL_WRKSRC}/unix/emacs/mozc.elc \
		${FILESDIR}/leim-list.el \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/

.endif

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

post-install:
	cd ${BAZEL_WRKSRC} && bazel ${BAZEL_BOOT} shutdown

_USES_fetch+=	800:fetch-bcr
fetch-bcr:
.if defined(FORCE_FETCH_ALL)
	${RM} -r ${BAZEL_BCR_LOCAL}
.endif
.if ! exists(${BAZEL_BCR_LOCAL})
	cd ${DISTDIR} && git clone ${BAZEL_BCR_URL}
.else
. if make(fetch)
	cd ${BAZEL_BCR_LOCAL} && ( git pull 2> /dev/null || exit 0 )
. endif
.endif

bazel-mod: configure
	@cd ${BAZEL_WRKSRC} && \
		bazel ${BAZEL_BOOT} mod graph \
			--output text --charset ascii \
			${BAZEL_COMMON_OPTS} | \
		${SED} -E 's/[^[:alnum:]]+//;s/ .*//;' | \
		${GREP} '@[0-9]' | ${SORT} -u

bazel-modules: configure
	@cd ${BAZEL_WRKSRC} && \
		bazel ${BAZEL_BOOT} mod show_repo \
			$$( bazel ${BAZEL_BOOT} mod graph \
					--output text --charset ascii \
					${BAZEL_COMMON_OPTS} | \
				${SED} -E 's/[^[:alnum:]]+//;s/ .*//;' | \
				${GREP} '@[0-9]' | ${SORT} -u ) \
			--output text --charset ascii \
			${BAZEL_COMMON_OPTS} | \
		${AWK} -F / ' / urls = / { \
			sub(/.* urls = \["/, ""); sub(/"\],/, ""); \
			group=$$5; gsub(/-/, "_", group); \
			printf( "MASTER_SITES+=\t%s/%s/%s/%s/%s/%s/%s/%s/:%s\n", \
				$$1, $$2, $$3, $$4, $$5, $$6, $$7, $$8, group ); \
			printf( "DISTFILES+=\t%s:%s\n", $$9, group ); \
			} ' > ${MASTERDIR}/Makefile.MASTER_SITES

# Create new distinfo: `make renew-makesum`
renew-makesum:
	@for url in `${MAKE} fetch-url-list | ${GREP} -v 'FreeBSD\.org'`; do \
		case $${url} in \
		*${UTDIC_DISTFILES:M*\:title:C@\:title@@}) urls="$${urls} $${url}" ;; \
		*${DISTFILES:M*\:kenall:C@\:kenall@@}) urls="$${urls} $${url}" ;; \
		*${DISTFILES:M*\:jigyosyo:C@\:jigyosyo@@}) urls="$${urls} $${url}" ;; \
		*) continue ;; \
		esac ; \
	done && \
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		for url in $${urls}; do \
			${FETCH_BINARY} -Fmp $${url} ; \
		done
	@${MAKE} makesum

.include <bsd.port.post.mk>

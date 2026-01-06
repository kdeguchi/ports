PORTNAME=	ghostty
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	x11 wayland
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	slowdive@me.com
COMMENT=	Fast, native and feature-rich terminal emulator with GPU acceleration
WWW=		https://github.com/ghostty-org/ghostty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	blueprint-compiler>0:devel/blueprint-compiler
LIB_DEPENDS=	libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell \
		libonig.so:devel/oniguruma \
		libsimdutf.so:converters/simdutf

USES=		gettext-runtime gettext-tools gnome pkgconfig zig:014
USE_GITHUB=	yes
GH_ACCOUNT=	ghostty-org

USE_GNOME=	glib20 gtk40 libadwaita libxml2

ZIG_ARGS=	-Dapp-runtime=gtk \
		-Dgtk-wayland=true \
		-Dgtk-x11=true \
		-fsys=simdutf \
		-fno-sys=spirv-cross

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
ZIG_BOOL=		emit-docs
.endif

.include <bsd.port.mk>

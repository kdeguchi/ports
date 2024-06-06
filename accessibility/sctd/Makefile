PORTNAME=	sctd
DISTVERSION=	0.3.0
CATEGORIES=	accessibility

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Set color temperature (sct) daemon
WWW=		https://github.com/amir/sctd

LICENSE=	CC0-1.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE

PATCH_SITES=	https://github.com/amir/${PORTNAME}/commit/
PATCHFILES=	86ae6e4ff18477f0d598367fba09f940b7b62cd8.patch:-p1

USES=			cargo xorg
USE_GITHUB=		yes
GH_ACCOUNT=		amir
USE_XORG=		x11 xrandr
CARGO_CRATES=	android_system_properties-0.1.5 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bumpalo-3.11.0 \
		cfg-if-1.0.0 \
		chrono-0.4.22 \
		clap-3.2.22 \
		clap_lex-0.2.4 \
		core-foundation-sys-0.8.3 \
		env_logger-0.9.1 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		iana-time-zone-0.1.48 \
		indexmap-1.9.1 \
		js-sys-0.3.60 \
		libc-0.2.133 \
		log-0.4.17 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		once_cell-1.14.0 \
		os_str_bytes-6.3.0 \
		pkg-config-0.3.25 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		spa-0.3.0 \
		strsim-0.10.0 \
		syn-1.0.100 \
		termcolor-1.1.3 \
		textwrap-0.15.1 \
		time-0.1.44 \
		unicode-ident-1.0.4 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-2.20.0

PLIST_FILES=	bin/sctd

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sctd

.include <bsd.port.mk>

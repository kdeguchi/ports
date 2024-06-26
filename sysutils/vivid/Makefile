PORTNAME=	vivid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
#PORTREVISION=	21
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Themeable LS_COLORS generator with a rich filetype datebase
WWW=		https://github.com/sharkdp/vivid

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	ansi_colours-1.2.1 \
		bitflags-1.3.2 \
		block-buffer-0.10.4 \
		bytemuck-1.13.1 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		clap-4.1.8 \
		clap_lex-0.3.2 \
		cpufeatures-0.2.5 \
		crypto-common-0.1.6 \
		digest-0.10.6 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		generic-array-0.14.6 \
		getrandom-0.2.8 \
		hermit-abi-0.3.1 \
		io-lifetimes-1.0.6 \
		is-terminal-0.4.4 \
		lazy_static-1.4.0 \
		libc-0.2.140 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.1.4 \
		once_cell-1.17.1 \
		os_str_bytes-6.4.1 \
		proc-macro2-1.0.52 \
		quote-1.0.26 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		rgb-0.8.36 \
		rust-embed-6.6.0 \
		rust-embed-impl-6.5.0 \
		rust-embed-utils-7.5.0 \
		rustix-0.36.9 \
		same-file-1.0.6 \
		sha2-0.10.6 \
		strsim-0.10.0 \
		syn-1.0.109 \
		termcolor-1.2.0 \
		terminal_size-0.2.5 \
		thiserror-1.0.39 \
		thiserror-impl-1.0.39 \
		typenum-1.16.0 \
		unicode-ident-1.0.8 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.2 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_msvc-0.42.2 \
		windows_i686_gnu-0.42.2 \
		windows_i686_msvc-0.42.2 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_msvc-0.42.2 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/vivid

.include <bsd.port.mk>

# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	libsecret
PORTVERSION=	0.20.5
PORTREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

LICENSE=	LGPL21

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 intltool

OPTIONS_DEFINE=	BASH DOCS GCRYPT GIR MANPAGES NLS TPM2 VAPI
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	DOCS GCRYPT GIR MANPAGES NLS VAPI

BASH_BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion
BASH_MESON_ENABLED=	bash_completion
BASH_MESON_ON=		-Dbashcompdir=${PREFIX}/etc/bash_completion.d

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	gtk_doc

GCRYPT_DESC=		Build with gcrypt and transport encryption
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_MESON_TRUE=	gcrypt

GIR_DESC=		Build introspection data
GIR_USE=		GNOME=introspection
GIR_MESON_TRUE=	introspection

NLS_USES=		gettext-runtime
NLS_MESON_ENABLED=	nls

MANPAGES_BUILD_DEPENDS=docbook-xsl>=0:textproc/docbook-xsl
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_MESON_TRUE=	manpage

TPM2_DESC=		Build with TPM2 Software Stack support
TPM2_LIB_DEPENDS=	libtss2-sys.so:security/tpm2-tss
TPM2_MESON_TRUE=	tpm2

VAPI_BUILD_DEPENDS=	vala>=0.20:lang/vala
VAPI_MESON_TRUE=	vapi

.include <bsd.port.mk>

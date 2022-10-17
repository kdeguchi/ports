PORTNAME?=	fetchmail
DISTVERSION=	7.0.0
PORTREVISION?=	0
CATEGORIES=	mail

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT?=	Batch mail retrieval utility for IMAP/POP3/ETRN/ODMR/OAuth2
WWW=		https://www.fetchmail.info/

LICENSE=	GPLv2+

.if empty(MASTERDIR)
USES=		autoreconf cpe gmake ssl tar:xz
IGNORE_SSL=	libressl libressl-devel
IGNORE_SSL_REASON=	incompatible license/no GPLv2 clause 2b exception for LibreSSL
# The Free Software Foundation asserts that a GPL v2 clause 2b exception is
# required even for dynamically linked binaries. See
# https://www.gnu.org/licenses/gpl-faq.en.html#GPLStaticVsDynamic

USE_GITLAB=	yes
GL_ACCOUNT=	${PORTNAME}
GL_PROJECT=	${PORTNAME}
GL_COMMIT=	30b368fb8660d8fec08be1cdf2606c160b4bcb80

USE_RC_SUBR=	fetchmail

GNU_CONFIGURE=	yes

# the added PYTHON=: suppresses python builds,
# see ../../mail/fetchmailconf/ for the configuration tool
CONFIGURE_ARGS=	--enable-RPA \
		--enable-SDPS \
		--without-hesiod \
		PYTHON=:

# -Wl,--as-needed suppresses unneeded library references,
# for instance, libcom_err.so on GSSAPI_NONE builds:
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed

SUB_FILES=	pkg-message
USERS=		${PORTNAME}
GROUPS=		${USERS}

PORTDOCS=	FAQ FEATURES NEWS NOTES OLDNEWS README README.SSL \
		README.SSL-SERVER design-notes.html esrs-design-notes.html \
		fetchmail-FAQ.html fetchmail-features.html todo.html

OPTIONS_DEFINE=		CA_BUNDLE DOCS NLS OAUTH2
OPTIONS_DEFAULT=	CA_BUNDLE GSSAPI_BASE OAUTH2 OPENSSL
OPTIONS_SINGLE=		GSSAPI TLS
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_TLS=	OPENSSL WOLFSSL

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Install CA bundle for OpenSSL
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi=${GSSAPIBASEDIR}
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-kerberos5=${GSSAPIBASEDIR}
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

OPENSSL_CONFIGURE_WITH=	ssl=${OPENSSLBASE}

OAUTH2_DESC=	OAuth2 Support
OAUTH2_MASTER_SITES=	http://mmogilvi.users.sourceforge.net/downloads/:oauth2
OAUTH2_DISTFILES=	oauthbearerScripts-2019-12-11.tar.bz2:oauth2
OAUTH2_USES=	python shebangfix
SHEBANG_FILES+=	${WRKDIR}/oauthbearerScripts/fetchmail-oauth2.py

WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
WOLFSSL_USES_OFF=	ssl
WOLFSSL_CONFIGURE_ON=	WOLFSSL_TRUST_FILE=${LOCALBASE}/share/certs/ca-root-nss.crt
WOLFSSL_CONFIGURE_WITH=	wolfssl=${LOCALBASE}

.endif

.if empty(MASTERDIR)
post-build:
	${MAKE_CMD} -C ${WRKSRC} check ; { r=$$? ; ( set -x ; ${CAT} "${WRKSRC}/test-suite.log" ) ; exit $$r ; }

post-install:
	${INSTALL} -d ${STAGEDIR}/var/run/fetchmail
	${INSTALL_DATA} ${FILESDIR}/fetchmailrc.sample \
		${STAGEDIR}${PREFIX}/etc/fetchmailrc.sample
	${RM} ${STAGEDIR}${PREFIX}/bin/fetchmailconf
	${RM} ${STAGEDIR}${PREFIX}/man/man1/fetchmailconf.1*

post-install-OAUTH2-on:
	${INSTALL_SCRIPT} ${WRKDIR}/oauthbearerScripts/fetchmail-oauth2.py \
		${STAGEDIR}${PREFIX}/bin/fetchmail-oauth2.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.endif

.include <bsd.port.pre.mk>

.if (${OPSYS} == FreeBSD && ${OSVERSION} < 1400072) || ${OPSYS} != FreeBSD
CONFIGURE_ARGS+=	--enable-opie
.endif

.if ${OPSYS} == FreeBSD && (${ARCH:Mpowerpc*} && ${OSREL:R} < 13)
# as of 2019-10-02, powerpc's base compiler does not yield a working fetchmail.
# https://svnweb.freebsd.org/ports?view=revision&revision=513614 -- pkubaj@
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>

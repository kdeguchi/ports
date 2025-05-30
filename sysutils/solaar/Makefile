PORTNAME=	solaar
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Device manager for the Logitech Unifying Receiver
WWW=		https://pwr-solaar.github.io/Solaar/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# libhidapi.so is only loaded at runtime via ctypes (dlopen)
RUN_DEPENDS=	${LOCALBASE}/lib/libhidapi.so:comms/hidapi

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pwr-Solaar
GH_PROJECT=	Solaar
USE_PYTHON=	autoplist concurrent distutils optsuffix

NO_ARCH=	yes

OPTIONS_DEFINE=	GUI NLS

GUI_USES=	gnome
GUI_USE=	GNOME=pygobject3:run

NLS_USES=	gettext

post-patch:
	@${CP} ${FILESDIR}/hidapi.py ${WRKSRC}/lib/hidapi/udev.py
	@${REINPLACE_CMD} -e '/pyudev/d' \
		-e 's|python-gi|${PYTHON_PKGNAMEPREFIX}gobject3|' \
		${WRKSRC}/lib/solaar/gtk.py
	@${REINPLACE_CMD} 's|receiver\.path\.split.*|receiver.path)|' \
		${WRKSRC}/lib/logitech_receiver/listener.py
	@${REINPLACE_CMD} 's|[[:<:]]cmd[[:>:]]|action|' \
		${WRKSRC}/lib/solaar/cli/__init__.py
	@${REINPLACE_CMD} -e 's@/etc/xdg/autostart@${PREFIX}/etc/xdg/autostart@' \
		-e "s@yield 'share/solaar/udev-rules\.d.*@yield 'etc/xdg/autostart', ['share/autostart/solaar.desktop']@" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's@mkdir --parents@mkdir -p@;s@/usr/bin/msgfmt@${PREFIX}/bin/msgfmt@' \
		${WRKSRC}/tools/po-compile.sh
	@${CP} ${FILESDIR}/ja.po ${WRKSRC}/po

post-build:
	${AWK} -f ${FILESDIR}/devd-solaar.awk \
		${WRKSRC}/rules.d/42-logitech-unify-permissions.rules \
		> ${WRKDIR}/solaar.conf.sample

post-build-NLS-on:
	@cd ${WRKSRC} && ${SH} tools/po-compile.sh

post-install:
	${INSTALL_DATA} ${WRKDIR}/solaar.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>

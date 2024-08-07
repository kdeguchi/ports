PORTNAME=	fcitx5-configtool
DISTVERSION=	5.1.6
CATEGORIES=	textproc x11
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Fcitx5 IM framework configuration tool
WWW=		https://github.com/fcitx/fcitx5-configtool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

BUILD_DEPENDS=	fcitx5-qt6>=5.1.5:textproc/fcitx5-qt@qt6 \
		fcitx5>=5.1.9:textproc/fcitx5 \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libFcitx5Qt6DBusAddons.so:textproc/fcitx5-qt@qt6 \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		xkeyboard-config>=0:x11/xkeyboard-config

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 pkgconfig qt:6 \
		tar:zst xorg

PLIST_SUB=	VER=${PORTVERSION}

USE_KDE=	config coreaddons ecm:build i18n iconthemes itemviews kcmutils \
		kdeclarative kirigami2 libplasma package service widgetsaddons
USE_GL=	opengl
USE_QT=	base declarative
USE_XORG=	x11 xkbfile
USE_LDCONFIG=	yes

CMAKE_ON=	USE_QT6 ENABLE_CONFIG_QT ENABLE_KCM
CMAKE_OFF=	ENABLE_TEST

.include <bsd.port.mk>

PORTNAME=	fcitx5-qt
DISTVERSION=	5.1.5
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT?=	Fcitx support for Qt (${FLAVOR})
WWW=		https://github.com/fcitx/fcitx5-qt

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_LGPL21+ =		${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libFcitx5Utils.so:textproc/fcitx5 \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS?=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

qt5_PKGNAMESUFFIX=	5
qt6_PKGNAMESUFFIX=	6

USES=		cmake compiler:c++17-lang gettext-tools kde:5 pkgconfig tar:xz \
		xorg

USE_KDE=	ecm
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb

CMAKE_OFF?=	ENABLE_QT4

.if ${FLAVOR} == qt5
RUN_DEPENDS=	fcitx5-qt-common>=${DISTVERSION}:textproc/fcitx5-qt-common
USES+=		qt:5
USE_QT=		concurrent core dbus gui widgets xml buildtools:build \
		qmake:build
CMAKE_ON=	ENABLE_QT5
CMAKE_OFF+=	ENABLE_QT6
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
.elif ${FLAVOR} == qt6
RUN_DEPENDS=	fcitx5-qt-common>=${DISTVERSION}:textproc/fcitx5-qt-common
USES+=		qt:6
USE_QT=		base wayland
CMAKE_ON=	ENABLE_QT6
CMAKE_OFF+=	ENABLE_QT5
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

PLIST?=		${PKGDIR}/pkg-plist.${FLAVOR}
PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>

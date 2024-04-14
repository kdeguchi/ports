PKGNAMESUFFIX=	-common

COMMENT=	Fcitx support for GTK (common files)

RUN_DEPENDS=	# empty

FLAVORS=	# empty
FLAVOR=	# empty

CMAKE_ON=	# empty
CMAKE_OFF=	ENABLE_GTK2_IM_MODULE ENABLE_GTK3_IM_MODULE \
		ENABLE_GTK4_IM_MODULE

MASTERDIR=	${.CURDIR}/../fcitx5-gtk

PLIST=	${MASTERDIR}/pkg-plist.common

.include "${MASTERDIR}/Makefile"

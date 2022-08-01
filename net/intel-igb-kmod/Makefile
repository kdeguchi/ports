PORTNAME=	igb
PORTVERSION=	2.5.21
PORTREVISION=	0
PORTEPOCH=	0
MASTER_SITE_SUBDIR=	682705

MAINTAINER=	freebsd@intel.com
COMMENT=	Network Adapter Driver for Intel(R) 82575/6 and 82580-Based Gigabit Network Connections

BROKEN_armv6=		fails to compile: implicit declaration of function 'cp15_pmccntr_get' is invalid in C99

MAX_NETMAP_OSVERSION=	1199999  # Doesn't build w/NETMAP on 12

MASTERDIR=	${.CURDIR}/../intel-ixl-kmod
PKGDIR=		${.CURDIR}
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"

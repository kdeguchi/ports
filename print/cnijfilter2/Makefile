PORTNAME=	cnijfilter2
PORTVERSION=	5.20
CATEGORIES=	print
MASTER_SITES=	http://gdlp01.c-wss.com/gds/1/0100006901/01/
DISTVERSIONSUFFIX=-1-rpm
#	cnijfilter2-5.20-1-rpm.tar.gz

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Caonon IJ Printer driver

USES=	linux
USE_LINUX=	avahi-libs cups-libs dbuslibs libxml2
USE_LINUX_PREFIX=	yes
USE_LDCONFIG=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64
LIBDIR_amd64=	/usr/lib64
LIBDIR_i386=	/usr/lib
PLIST=	pkg-plist.${ARCH}

OPTIONS_DEFINE=	DOCS

#RUN_DEPENDS=	${LINUXBASE}${LIBDIR_${ARCH}}/libusb.so:devel/linux_libusb

PPD_FILES=	canone460.ppd \
		canone480.ppd \
		canonib4000.ppd \
		canonip110.ppd \
		canonmb2000.ppd \
		canonmb2300.ppd \
		canonmb5000.ppd \
		canonmb5300.ppd \
		canonmg2900.ppd \
		canonmg3600.ppd \
		canonmg5600.ppd \
		canonmg5700.ppd \
		canonmg6600.ppd \
		canonmg6800.ppd \
		canonmg6900.ppd \
		canonmg7500.ppd \
		canonmg7700.ppd \
		canonmx490.ppd

.if defined(ARCH) && ${ARCH:Mamd64}
_ARCH=x86_64
_ARCH_amd64=x86_64
.elif defined(ARCH) && ${ARCH:Mi386}
_ARCH=i386
_ARCH_i386=i386
.endif

post-extract:
	cd ${WRKSRC}/packages && \
		${MKDIR} ${_ARCH_amd64} ${_ARCH_i386} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME:S/-rpm/.x86_64.rpm/} -C ./${_ARCH_amd64} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTNAME:S/-rpm/.i386.rpm/} -C ./${_ARCH_i386} && \
		${CP} -a ./${_ARCH_i386}${LIBDIR_i386}/* ./${_ARCH_amd64}${LIBDIR_i386}/ && \
		${RM} -r ./${_ARCH_i386}${LIBDIR_amd64}

do-install:
	cd ${WRKSRC}/packages/${_ARCH} && \
		${CP} -a usr ${STAGEDIR}${LINUXBASE} && \
		${RM} ${STAGEDIR}${LINUXBASE}${LOCALBASE}/bin/cnijlgmon3 && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/bin && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/backend && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter && \
		${MKDIR} ${STAGEDIR}${LOCALBASE}/share/cups/model
.for i in tocanonij tocnpwg
	${LN} -s ${LINUXBASE}${LOCALBASE}/bin/${i} ${STAGEDIR}${LOCALBASE}/bin/
.endfor
	${LN} -s ${LINUXBASE}${LIBDIR_${ARCH}}/cups/backend/cnijbe2 ${STAGEDIR}${LOCALBASE}/libexec/cups/backend/
.for i in cmdtocanonij2 rastertocanonij
	${LN} -s ${LINUXBASE}${LIBDIR_${ARCH}}/cups/filter/${i} ${STAGEDIR}${LOCALBASE}/libexec/cups/filter/
.endfor
.for i in ${PPD_FILES}
	${LN} -s ${LINUXBASE}/usr/share/cups/model/${i} ${STAGEDIR}${LOCALBASE}/share/cups/model/
.endfor

.include <bsd.port.mk>

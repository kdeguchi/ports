PORTNAME=	today
PORTVERSION=	2.12
PORTREVISION=	2
CATEGORIES=	japanese games
MASTER_SITES=	http://ftp.vector.co.jp/29/42/476/
DISTNAME=	ja-${PORTNAME}-${PORTVERSION}
DISTFILES=	td${PORTVERSION:S/.//}s.lzh \
		td${PORTVERSION:S/.//}m.lzh

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Tells you what day today is
WWW=		https://www.vector.co.jp/soft/dos/personal/se002657.html

EXTRACT_DEPENDS=nkf:japanese/nkf

NO_WRKSUBDIR=	yes
USES=		lha

MAKEFILE=	${FILESDIR}/Makefile

OPTIONS_DEFINE=	HISTDATA DOCS

HISTDATA_DESC=	More history data
HISTDATA_MASTER_SITES=	https://ftp.vector.co.jp/02/97/476/
HISTDATA_DISTFILES=	hst9602a.lzh \
		hst9602b.lzh \
		hst9602c.lzh
HISTDATA_EXTRA_PATCHES=	${PATCHDIR}/histdata-patch-gengo.tbl

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MHISTDATA}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-gengo.tbl \
		${PATCHDIR}/extra-patch-hist04.tbl
.endif

post-extract:
	@(cd ${WRKSRC}; lha xiqf utility.lzh src/dayinfo.c )
.if ${PORT_OPTIONS:MHISTDATA}
	@(cd ${WRKSRC}; ${MKDIR} backup; ${MV} hist*.tbl gengo.tbl backup; lha xqf tbl.lzh )
.endif
	@${ECHO_MSG} "===>  Extracting tbl file for ${DISTNAME}"
	@(cd ${WRKSRC}; lha xqf tbl.lzh )
.if ${PORT_OPTIONS:MHISTDATA}
	@(cd ${WRKSRC}; ${MV} backup/*.tbl . )
.endif
	@${ECHO_MSG} "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKSRC}; \
	for i in *.c *.h *.doc *.cnf *.rc birthday.tbl event*.tbl flower.tbl \
		gengo.tbl hist??.tbl history.tbl holiday.tbl magazine.tbl \
		monthly.tbl schedule.tbl suffix.tbl week.tbl; \
	do \
		nkf -Se $$i | ${TR} -d '\015' > $$i.tmp ;\
		${MV} -f $$i.tmp $$i ; \
	done)

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/*.cnf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/today.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

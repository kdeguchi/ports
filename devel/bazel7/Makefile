PORTNAME=	bazel
DISTVERSION=	7.4.0
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/bazelbuild/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	bazel-${DISTVERSION}-dist
PKGNAMESUFFIX=	7

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Fast and correct build system
WWW=		https://bazel.build/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

BUILD_DEPENDS=	bash:shells/bash \
		python3:lang/python3 \
		zip:archivers/zip

RUN_DEPENDS=	bash:shells/bash \
		python3:lang/python3

USES=		cpe python:3.8+ shebangfix zip

CPE_VENDOR=	google

USE_JAVA=	yes
JAVA_VERSION=	21
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes

SHEBANG_REGEX=	.*(sh|txt|_stub|stub_.*|bazel|get_workspace_status|protobuf_support|_so)

CONFLICTS_INSTALL=	bazel[0-9]* bazel

CFLAGS+=	-Wno-gnu-offsetof-extensions
# The bazel binary is also a zip archive (extracted by the elf part), it must not be stripped
STRIP=

NO_WRKSUBDIR=	YES

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64"
BAZEL_JAVAC_OPTS+=	"-J-Xmx1g -J-Xms128m"
.endif

# Have the location of the system-wide rc file reside ${ETCDIR}.
# Also adapt the sample file to disable persistent java workers as they
# do not work reliably on FreeBSD.
post-patch:
	@${REINPLACE_CMD} -i '' -e "s|/etc/bazel.bazelrc|${ETCDIR}/bazel.bazelrc|" \
		${WRKSRC}/src/main/cpp/BUILD
	@${ECHO_CMD} build --strategy=Javac=standalone >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --java_runtime_version=${JAVA_VERSION} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --tool_java_runtime_version=${JAVA_VERSION} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --action_env=PATH=/bin:/usr/bin/:${LOCALBASE}/bin >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${REINPLACE_CMD} -i '' -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' \
		${WRKSRC}/src/main/cpp/blaze_util_bsd.cc

do-build:
	@${MKDIR} ${WRKDIR}/bazel_tmp
	(if [ -z "$${SOURCE_DATE_EPOCH}" ] ; \
	  then SOURCE_DATE_EPOCH=`grep TIMESTAMP ${DISTINFO_FILE} \
	    | ${SED} -e 's/[^0-9]//g'`; \
	fi ; \
	cd ${WRKSRC} && \
	${SETENV} BAZEL_SH=${LOCALBASE}/bin/bash \
	JAVA_HOME=${JAVA_HOME} \
	JAVA_VERSION=${JAVA_VERSION} \
	TMPDIR=${WRKDIR}/bazel_tmp \
	EMBED_LABEL='${PORTVERSION}' \
	PATH=${LOCALBASE}/bin:$$PATH \
	SOURCE_DATE_EPOCH=$${SOURCE_DATE_EPOCH} \
	BAZEL_JAVAC_OPTS=${BAZEL_JAVAC_OPTS} \
	EXTRA_BAZEL_ARGS='--tool_java_runtime_version=local_jdk --java_language_version=${JAVA_VERSION} --tool_java_language_version=${JAVA_VERSION}' \
	${LOCALBASE}/bin/bash ./compile.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc ${STAGEDIR}${ETCDIR}/bazel.bazelrc.sample

pre-clean:
.if exist(WRKDIR)
	@${CHMOD} -R u+w ${WRKDIR}
.endif

.include <bsd.port.post.mk>

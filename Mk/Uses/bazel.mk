# This file contains logic to ease porting of bazel binaries using the
# `bazel` command.
#
# Feature:	bazel
# Usage:	USES=bazel
# Valid ARGS:	(none), N, mode, build, run
#
# (none)	Setup BAZEL_VERSION=6, BAZEL_MODE=workspace and adds it to BUILD_DEPENDS.
# N		Specify bazel version.
# mode		Add workspace or bzlmod to BAZEL_MODE.
# build		Indicates that bazel is needed at run time and adds it to
#		BUILD_DEPENDS.
# run		Indicates that bazel is needed at run time and adds it to
#		RUN_DEPENDS.
#
# You can set the following variables to control the process.
#
# GO_MODULE
#	The name of the module as specified by "module" directive in go.mod.
#	In most cases, this is the only required variable for ports that
#	use Go modules.
#
# GO_MOD_DIST
#       The location to download the go.mod file if GO_MODULE is used.
#       The default is empty, so it is loaded from GO_PROXY.
#       Set it to "gitlab" and make sure GL_PROJECT is defined to download
#       the "go.mod" from gitlab.
#       Set it to "github" and make sure GH_PROJECT is defined to download
#       the "go.mod" from github.
#       You can also set it completely manually a URI without go.mod in it,
#       is attached automatically to the URI.
#
# GO_PKGNAME
#	The name of the package when building in GOPATH mode.  This
#	is the directory that will be created in ${GOPATH}/src.  If not set
#	explicitly and GH_SUBDIR or GL_SUBDIR is present, GO_PKGNAME will
#	be inferred from it.
#	It is not needed when building in modules-aware mode.
#
# GO_TARGET
#	The packages to build.  The default value is ${GO_PKGNAME}.
#	GO_TARGET can also be a tuple in the form package:path where path can be
#	either a simple filename or a full path starting with ${PREFIX}.
#
# GO_TESTTARGET
#	The packages to test. The default value is `./...` (the current package
#	and all subpackages).
#
# CGO_CFLAGS
#	Additional CFLAGS variables to be passed to the C compiler by the `go`
#	command
#
# CGO_LDFLAGS
#	Additional LDFLAGS variables to be passed to the C compiler by the `go`
#	command
#
# GO_BUILDFLAGS
#	Additional build arguments to be passed to the `go build` command
#
# GO_TESTFLAGS
#	Additional build arguments to be passed to the `go test` command
#
# MAINTAINER: go@FreeBSD.org

.if !defined(_INCLUDE_USES_BAZEL_MK)
_INCLUDE_USES_BAZEL_MK=	yes

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
BAZEL_VALID_VERSIONS=	5 6 7

# Check arguments sanity
.  if !empty(bazel_ARGS:N[1-9]:Nbzlmod:Nworkspace:Nbuild:Nrun)
IGNORE=	USES=bazel has invalid arguments: ${bazel_ARGS:N[1-9]:Nbzlmod:Nworkspace:Nbuild:Nrun}
.  endif

# Parse bazel version
BAZEL_VERSION=	${bazel_ARGS:Nbzlmod:Nworkspace:Nbuild:Nrun:C/^$/${BAZEL_DEFAULT}/}
.  if empty(BAZEL_VALID_VERSIONS:M${BAZEL_VERSION})
IGNORE?= USES=bazel has invalid version number: ${BAZEL_VERSION}
.  endif

BAZEL_PORT=	devel/bazel${BAZEL_VERSION:N6}

.  if ! empty(bazel_ARGS:Mworkspace)
BAZEL_MODE=	workspace
.  elseif ! empty(bazel_ARGS:Mbzlmod)
BAZEL_MODE=	blzmod
.  else
BAZEL_MODE=	workspace
.  endif

.  if ! empty(bazel_ARGS:Mbuild)
BUILD_DEPENDS+=	${BAZEL_PORT}
.  elseif ! empty(bazel_ARGS:Mrun)
RUN_DEPENDS+=	${BAZEL_PORT}
.  else
BUILD_DEPENDS+=	${BAZEL_PORT}
.  endif

BAZEL_CMD=	${LOCALBASE}/bin/bazel
BAZEL_DISTDIR=	${DISTDIR}/bazel
BAZEL_BCR_URL?=	https://github.com/bazelbuild/bazel-central-registry.git
BAZEL_BCR_DIR=	bcr
BAZEL_BCR_LOCAL=	${BAZEL_DISTDIR}/${BAZEL_BCR_DIR}
BAZEL_OUTPUT_BASE=	${WRKDIR}/bazel_base
BAZEL_OUTPUT_USER_ROOT=	${WRKDIR}/bazel_out

BAZEL_BOOT=	--output_base=${BAZEL_OUTPUT_BASE} \
		--output_user_root=${BAZEL_OUTPUT_USER_ROOT}

BAZEL_OPTS=	--distdir=${BAZEL_DISTDIR}

.  if ${BAZEL_VERSION} > 5 && ${BAZEL_MODE:Mbzlmod}

BAZEL_BOOT+=	--enable_bzlmod
BAZEL_OPTS+=	--registry=${BAZEL_BCR_LOCAL}

FETCH_DEPENDS+=	git:devel/git

_USES_fetch+=	800:fetch-bcr

fetch-bcr:
.    if ! exists(BAZEL_BCR_LOCAL)
	cd ${BAZEL_DISTDIR} && \
		git clone ${BAZEL_BCR_URL} ${BAZEL_BCR_DIR}
.    else
	cd ${BAZEL_BCR_LOCAL} && git pull || exit 0
.    endif

bazel-modules: configure
	cd ${WRKSRC} && \
		${BAZEL_CMD} ${BAZEL_BOOT} mod show_repo $$( cd ${BUILD_WRKSRC} && \
			bazel ${BAZEL_BOOT} mod graph \
				--output text --charset ascii \
				${BAZEL_OPTS} | \
				${SED} -E 's/[_]+//;s/\|//g;s/^ +//;s/ .*//;' | \
				${GREP} '@[0-9]' | sort -u ) \
			--output text --charset ascii \
			${BAZEL_COMMON_OPTS} | \
		${AWK} -F / ' / urls = / { \
			sub(/.* urls = \["/, ""); sub(/"\],/, ""); \
			group=$$5; gsub(/-/, "_", group); \
			printf( "MASTER_SITES+=\t%s/%s/%s/%s/%s/%s/%s/%s/:%s\n", $$1, $$2, $$3, $$4, $$5, $$6, $$7, $$8, group ); \
			printf( "DISTFILES+=\t%s:%s\n", $$9, group ); \
		} ' > ${MASTERDIR}/Makefile.MASTER_SITES

.  endif


.endif

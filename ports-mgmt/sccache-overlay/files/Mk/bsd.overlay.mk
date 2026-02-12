.if !defined(_SCCACHE_OVERLAY_INCLUDED) && !defined(NO_CCACHE)
_SCCACHE_OVERLAY_INCLUDED=	yes

SCCACHE_SERVER_UDS?=	/tmp/sccache-overlay.socket
SCCACHE_CONF?=		${SCCACHE_DIR}/config
SCCACHE_IDLE_TIMEOUT?=	0

.  if exists(/ccache/bin/sccache)
SCCACHE_BIN?=	/ccache/bin/sccache
.  else
.    for overlay in ${OVERLAYS}
.      if exists(${overlay}/bin/sccache)
SCCACHE_BIN?=	${overlay}/bin/sccache
.      break
.      endif
.    endfor
.  endif
SCCACHE_BIN?=	${LOCALBASE}/share/sccache/overlay/bin/sccache
.  if !exists(${SCCACHE_BIN})
IGNORE=		could not find sccache: ${SCCACHE_BIN}
.  endif

.  ifdef CCACHE_DIR
SCCACHE_DIR?=	${CCACHE_DIR}/sccache
.  endif
.  ifndef SCCACHE_DIR
IGNORE=		SCCACHE_DIR not set
.  endif

_SCCACHE_ENV=	SCCACHE_SERVER_UDS="${SCCACHE_SERVER_UDS}" \
		SCCACHE_CONF="${SCCACHE_CONF}" \
		SCCACHE_DIR="${SCCACHE_DIR}" \
		SCCACHE_IDLE_TIMEOUT="${SCCACHE_IDLE_TIMEOUT}" \
		RUSTC_WRAPPER="${SCCACHE_BIN}"
CONFIGURE_ENV+=	${_SCCACHE_ENV}
MAKE_ENV+=	${_SCCACHE_ENV}

_USES_configure+=	250:sccache-start
_USES_stage+=		996:sccache-stats

sccache-start:
	@${ECHO_MSG} "==> Starting sccache"
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --start-server || ${TRUE}
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --show-stats

sccache-stats:
	@${ECHO_MSG} "==> sccache statistics"
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --show-stats || ${TRUE}

# We let Poudriere clean up the server. Users who build locally
# can stop the server with `make sccache-stop` manually.
sccache-stop:
	@${ECHO_MSG} "==> Stopping sccache"
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --stop-server

.endif

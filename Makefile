PKG_REPLACE_DB_DIR=	/var/db/pkg_replace

all:
	@${ECHO_MSG} "Checking different ports..."
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		file="${PKG_REPLACE_DB_DIR}/$$(md5 -s "${.CURDIR}/$${i}").pkgname"; \
		my=$$( ([ -f "$${file}" ] && cat "$${file}") || (cd $${i} && ${MAKE} -V PKGNAME) ) || continue; \
		file="${PKG_REPLACE_DB_DIR}/$$(md5 -s "${PORTSDIR}/$${i}").pkgname"; \
		orig=$$( ([ -f "$${file}" ] && cat "$${file}") || ([ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME ) ) || continue; \
		${PRINTF} "%-$$(tput co)s\r" $${orig}; \
		check=$$( ${PKG_VERSION} --test-version $${orig} $${my} ); \
		[ "$${check}" = ">" ] && ${PRINTF} "%-$$(tput co)s\n" "update $${my}" || continue; \
	done

.include <bsd.port.mk>

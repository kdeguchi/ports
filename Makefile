all:
	@${ECHO_MSG} "Checking different ports..."
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		my=$$( cd $${i} && ${MAKE} -V PKGNAME ) || continue; \
		orig=$$( [ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME ) || \
			continue; \
		${PRINTF} "%-$$(tput co)s\r" $${orig}; \
		check=$$( ${PKG_VERSION} --test-version $${orig} $${my} ); \
		[ "$${check}" = ">" ] && ${PRINTF} "%-$$(tput co)s\n" "update $${my}" || continue; \
	done

.include <bsd.port.mk>

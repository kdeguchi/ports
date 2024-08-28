all:
	@${ECHO_MSG} "Checking different ports..."
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		my=$$( cd $${i} && ${MAKE} -V PKGNAME ) || continue; \
		orig=$$( [ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME ) || \
			continue; \
		check=$$( ${PKG_VERSION} --test-version $${orig} $${my} ); \
		${PRINTF} "%-$$( tput co )s\r" $${orig}; \
		[ "$${check}" = ">" ] && ${PRINTF} "%-$$( tput co )s\t%s\t%s\n" "update" "$${check}" "$${i}" || continue; \
	done

.include <bsd.port.mk>

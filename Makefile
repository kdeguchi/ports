all:
	@${ECHO_MSG} "Checking different ports..."
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		my=$$( cd $${i} && ${MAKE} -V PKGNAME ) || continue; \
		orig=$$( [ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME ) || \
			continue; \
		check=$$( ${PKG_VERSION} --test-version $${orig} $${my} ); \
		[ "$${check}" = ">" ] && ${ECHO_MSG} -e "update\t$${check}\t$${i}" || continue; \
	done

.include <bsd.port.mk>

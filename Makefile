check-old:
	@${ECHO_MSG} Checking different ports...
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		my=$$( cd $${i} && ${MAKE} -V PKGNAME ) || continue; \
		orig=$$( [ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME ) || continue; \
		check=$$( ${PKG_VERSION} --test-version $${my} $${orig} ); \
		[ "${check}" = '<' ] && msg='update!' || msg=; \
		${ECHO_MSG} -e "$${check}\t$${msg}\t$${i}"; \
	done

.include <bsd.port.mk>

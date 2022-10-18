check-old:
	@${ECHO_MSG} Checking different ports...
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		my=$$( cd $${i} && ${MAKE} -V PKGNAME ) || continue; \
		orig=$$( [ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME ) || continue; \
		${ECHO_MSG} -e "$$( ${PKG_VERSION} --test-version $${my} $${orig} )\t$${i}"; \
	done

.include <bsd.port.mk>

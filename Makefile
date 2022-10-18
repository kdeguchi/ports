check-old:
	@${ECHO_MSG} Checking different ports...
	@for i in $$(${FIND} [a-z]*/* -depth 0 -type d); do \
		my=$$( cd $${i} && ${MAKE} -V PKGNAME) || continue; \
		orig=$$( [ -d ${PORTSDIR}/$${i} ] && cd ${PORTSDIR}/$${i} && ${MAKE} -V PKGNAME) || continue; \
		if [ $${my} != $${orig} ]; then \
			${ECHO_MSG} $${i}: $${my} $${orig}; \
		fi \
	done

.include <bsd.port.mk>

# $NetBSD: list-licenses.mk,v 1.1 2023/09/11 12:37:26 ryoon Exp $
#
# list-licenses:
#	Downloads the addon page of each language pack to determine the
#	license.
#
#	As of Firefox 70, the license information is not included in the
#	.xpi files themselves, therefore this seemed to be the best
#	alternative.

TOOL_DEPENDS+=	curl-[0-9]*:../../www/curl
USE_TOOLS+=	perl

# To declare WRKDIR; WRKSRC is still undefined.
.include "../../mk/bsd.prefs.mk"

list-licenses: .PHONY

.for locale in ${FIREFOX_LOCALES}
${WRKDIR}/${locale}.html:
	${RUN} \
	url="https://addons.mozilla.org/en-US/firefox/addon/langpack-${locale}@firefox.mozilla.org"; \
	${PREFIX}/bin/curl -ksSL "$$url" > ${.TARGET}.tmp; \
	${MV} ${.TARGET}.tmp ${.TARGET}

${WRKDIR}/${locale}.license: ${WRKDIR}/${locale}.html
	# Cannot use sed here since nbsed cannot handle long lines.
	# It gets caught in a seemingly endless loop.
	${RUN} ${PREFIX}/bin/perl -ne 'print "$$1\n" if /class="AddonMoreInfo-license-link" href="([^"]*)"/' \
		< ${WRKDIR}/${locale}.html > ${.TARGET}.tmp \
	&& ${MV} ${.TARGET}.tmp ${.TARGET}

list-licenses: show-license-${locale}

show-license-${locale}: .PHONY ${WRKDIR}/${locale}.license
	${RUN} printf '%s\t%s\n' ${locale:Q} "`${CAT} ${WRKDIR}/${locale}.license`"
.endfor

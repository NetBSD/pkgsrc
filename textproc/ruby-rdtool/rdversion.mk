# $NetBSD: rdversion.mk,v 1.3 2004/12/04 15:04:53 taca Exp $
#

.ifndef _RD_VERSION_MK
_RD_VERSION_MK=		# defined

.include "../../lang/ruby/rubyversion.mk"

RUBY_RD=		${LOCALBASE}/bin/rd2
RUBY_RD_VERSION =	0.6.14
RUBY_RD_REQD=		0.6.14

# create string for dependency list
RUBY_RD_LIST!=	${ECHO} ${RUBY_VERSION_LIST:S/^/ruby/g:S/$/-rdtool/} | \
			${SED} -e 's| |,|g'
.endif

# $NetBSD: rdversion.mk,v 1.4 2004/12/04 16:07:01 taca Exp $
#

.ifndef _RD_VERSION_MK
_RD_VERSION_MK=		# defined

.include "../../lang/ruby/rubyversion.mk"

RUBY_RD=		${LOCALBASE}/bin/rd2
RUBY_RD_VERSION =	0.6.14
RUBY_RD_REQD=		0.6.14

# create string for dependency list
RUBY_RD_LIST=	${RUBY_VERSION_LIST:C/([1-9][0-9]*)/ruby&-rdtool/g}
.endif

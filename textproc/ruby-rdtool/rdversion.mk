# $NetBSD: rdversion.mk,v 1.2 2004/12/01 15:32:39 taca Exp $
#

.ifndef _RD_VERSION_MK
_RD_VERSION_MK=		# defined

.include "../../lang/ruby/rubyversion.mk"

RUBY_RD=		${LOCALBASE}/bin/rd2
RUBY_RD_VERSION =	0.6.14
RUBY_RD_REQD=		0.6.14

# create depends list
.for f in ${RUBY_VERSION_LIST}
_RD_NAME+=	ruby${f}-rdtool
.endfor
RUBY_RD_LIST=	${_RD_NAME:ts,}

.endif

# $NetBSD: rdtool.mk,v 1.3 2023/06/06 12:42:34 riastradh Exp $

.if !defined(RUBY_RDTOOL_MK)

RUBY_RDTOOL_MK	:=

RUBY_RD=	${PREFIX}/bin/rd2${RUBY_SUFFIX}
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.14:../../textproc/ruby-rdtool

.endif # RUBY_RDTOOL_MK

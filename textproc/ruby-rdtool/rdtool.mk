# $NetBSD: rdtool.mk,v 1.4 2026/03/29 07:29:05 taca Exp $

.if !defined(RUBY_RDTOOL_MK)

RUBY_RDTOOL_MK:=

RUBY_RD=	${PREFIX}/bin/rd2${RUBY_SUFFIX}
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.14:../../textproc/ruby-rdtool

.endif # RUBY_RDTOOL_MK

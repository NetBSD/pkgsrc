# $NetBSD: rdtool.mk,v 1.2 2015/06/08 13:45:25 joerg Exp $

.if !defined(RUBY_RDTOOL_MK)

RUBY_RDTOOL_MK	:=

RUBY_RD=	${PREFIX}/bin/rd2${RUBY_SUFFIX}
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.14:../../textproc/ruby-rdtool

.endif # RUBY_RDTOOL_MK

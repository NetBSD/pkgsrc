# $NetBSD: rdtool.mk,v 1.1 2015/06/04 13:53:32 taca Exp $

.if !defined(RUBY_RDTOOL_MK)

RUBY_RDTOOL_MK	:=

RUBY_RD=	${PREFIX}/bin/rd2${RUBY_SUFFIX}
BUILD_DENEDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.14:../../textproc/ruby-rdtool

.endif # RUBY_RDTOOL_MK

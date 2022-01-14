# $NetBSD: Makefile,v 1.5 2022/01/14 15:58:50 taca Exp $

DISTNAME=	csv-${RUBY_CSV_VERSION}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/csv/
COMMENT=	CSV Reading and Writing
LICENSE=	2-clause-bsd

RUBY_CSV_VERSION=	3.1.9

# Ruby 3.0 and later contains newer version
RUBY_VERSIONS_ACCEPTED=	26 27

USE_LANGUAGES=	# none

#.include "../../lang/ruby/rubyversion.mk"
#
#.if !empty(RUBY_CSV_VER)
#
#.  if ${RUBY_CSV_VERSION} == "${RUBY_CSV_VER}"
#.    error "${RUBY_PKGPREFIX}-base contains this package ${PKGBASE}."
#.  endif
#
#.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

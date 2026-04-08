# $NetBSD: Makefile,v 1.4 2026/04/08 14:29:35 taca Exp $

DISTNAME=	pp-0.6.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/pp
COMMENT=	Provides a PrettyPrinter for Ruby objects
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=		# none

# Ruby 4.0.0 has the same version as a bundled gem.
RUBY_VERSIONS_ACCEPTED=	33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

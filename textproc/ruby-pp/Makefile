# $NetBSD: Makefile,v 1.1 2025/05/22 13:34:24 taca Exp $

DISTNAME=	pp-0.6.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/pp
COMMENT=	Provides a PrettyPrinter for Ruby objects
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=		# none

# Ruby 3.4.4 has the same version as a bundled gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

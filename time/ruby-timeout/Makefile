# $NetBSD: Makefile,v 1.5 2025/05/22 14:25:36 taca Exp $

DISTNAME=	timeout-0.4.3
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/timeout
COMMENT=	Auto-terminate potentially long-running operations in Ruby
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.4 has timeout 0.4.3 gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

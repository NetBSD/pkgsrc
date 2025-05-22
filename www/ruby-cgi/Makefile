# $NetBSD: Makefile,v 1.3 2025/05/22 14:25:37 taca Exp $

DISTNAME=	cgi-0.4.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/cgi
COMMENT=	Support for the Common Gateway Interface protocol
LICENSE=	2-clause-bsd OR ruby-license

#USE_LANGUAGES=	# none

# Ruby 3.4.4 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

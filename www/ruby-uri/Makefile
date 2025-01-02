# $NetBSD: Makefile,v 1.5 2025/01/02 06:36:12 taca Exp $

DISTNAME=	uri-1.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/uri
COMMENT=	Providing classes to handle Uniform Resource Identifiers
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.1 has uri 1.0.2 gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

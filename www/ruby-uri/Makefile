# $NetBSD: Makefile,v 1.11 2026/01/18 15:43:21 taca Exp $

DISTNAME=	uri-1.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/uri
COMMENT=	Providing classes to handle Uniform Resource Identifiers
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 4.0.0 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	32 33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

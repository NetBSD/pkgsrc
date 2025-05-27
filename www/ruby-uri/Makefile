# $NetBSD: Makefile,v 1.9 2025/05/27 16:05:34 taca Exp $

DISTNAME=	uri-1.0.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/uri
COMMENT=	Providing classes to handle Uniform Resource Identifiers
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.4 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

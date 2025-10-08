# $NetBSD: Makefile,v 1.10 2025/10/08 14:15:37 taca Exp $

DISTNAME=	uri-1.0.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/uri
COMMENT=	Providing classes to handle Uniform Resource Identifiers
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# Ruby 3.4.7 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

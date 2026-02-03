# $NetBSD: Makefile,v 1.2 2026/02/03 16:05:54 taca Exp $

DISTNAME=	faraday-retry-1.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/retry/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-retry
COMMENT=	Catches exceptions and retries each request a limited times
LICENSE=	mit

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	32 33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

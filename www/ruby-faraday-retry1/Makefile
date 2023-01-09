# $NetBSD: Makefile,v 1.1 2023/01/09 07:41:01 taca Exp $

DISTNAME=	faraday-retry-1.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/retry/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-retry
COMMENT=	Catches exceptions and retries each request a limited times
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

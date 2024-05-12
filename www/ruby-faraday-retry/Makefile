# $NetBSD: Makefile,v 1.5 2024/05/12 16:30:02 taca Exp $

DISTNAME=	faraday-retry-2.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-retry
COMMENT=	Catches exceptions and retries each request a limited times
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.0<3:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

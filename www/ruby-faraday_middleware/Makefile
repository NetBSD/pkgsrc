# $NetBSD: Makefile,v 1.6 2026/02/03 16:07:54 taca Exp $

DISTNAME=	faraday_middleware-1.2.1
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday_middleware
COMMENT=	Various middleware for Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday1>=1.0<2:../../www/ruby-faraday1

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	32 33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

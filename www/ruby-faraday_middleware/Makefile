# $NetBSD: Makefile,v 1.3 2020/06/14 16:27:53 taca Exp $

DISTNAME=	faraday_middleware-1.0.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday_middleware
COMMENT=	Various middleware for Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=1.0<2:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

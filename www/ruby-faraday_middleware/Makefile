# $NetBSD: Makefile,v 1.4 2021/09/19 17:49:58 taca Exp $

DISTNAME=	faraday_middleware-1.1.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday_middleware
COMMENT=	Various middleware for Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=1.0<2:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

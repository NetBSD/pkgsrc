# $NetBSD: Makefile,v 1.5 2023/01/09 07:55:38 taca Exp $

DISTNAME=	faraday_middleware-1.2.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday_middleware
COMMENT=	Various middleware for Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday1>=1.0<2:../../www/ruby-faraday1

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

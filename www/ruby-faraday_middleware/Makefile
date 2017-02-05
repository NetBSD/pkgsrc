# $NetBSD: Makefile,v 1.1 2017/02/05 10:57:47 tsutsui Exp $

DISTNAME=	faraday_middleware-0.11.0.1
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday_middleware
COMMENT=	Various middleware for Faraday
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.7.4<1.0:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

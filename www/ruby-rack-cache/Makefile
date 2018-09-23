# $NetBSD: Makefile,v 1.9 2018/09/23 17:03:33 taca Exp $

DISTNAME=	rack-cache-1.8.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/rack-cache
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=0.4:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

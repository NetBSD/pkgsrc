# $NetBSD: Makefile,v 1.14 2021/12/11 15:40:24 taca Exp $

DISTNAME=	rack-cache-1.13.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/rack-cache
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.4:../../www/ruby-rack

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

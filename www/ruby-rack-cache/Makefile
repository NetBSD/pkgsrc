# $NetBSD: Makefile,v 1.12 2020/06/07 15:52:26 taca Exp $

DISTNAME=	rack-cache-1.12.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/rack-cache
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.4:../../www/ruby-rack

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2023/12/17 16:30:38 taca Exp $

DISTNAME=	rack-cache-1.15.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-cache
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.4:../../www/ruby-rack

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

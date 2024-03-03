# $NetBSD: Makefile,v 1.17 2024/03/03 08:52:52 taca Exp $

DISTNAME=	rack-cache-1.16.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-cache
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.4:../../www/ruby-rack

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

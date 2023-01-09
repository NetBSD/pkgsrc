# $NetBSD: Makefile,v 1.2 2023/01/09 12:55:31 taca Exp $

DISTNAME=	faraday-rack-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-rack
COMMENT=	Faraday adapter for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.0<3:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

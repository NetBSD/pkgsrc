# $NetBSD: Makefile,v 1.3 2024/09/22 08:08:46 taca Exp $

DISTNAME=	faraday-excon-2.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/excon/faraday-excon
COMMENT=	Faraday adapter for Excon
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-excon>=0.27.4:../../www/ruby-excon
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.0<3:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

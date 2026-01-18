# $NetBSD: Makefile,v 1.3 2026/01/18 15:00:08 taca Exp $

DISTNAME=	faraday-follow_redirects-0.5.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tisba/faraday-follow-redirects
COMMENT=	FaradayMiddleware::FollowRedirects for Faraday 2.x
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.0<3:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2025/11/03 06:01:15 taca Exp $

DISTNAME=	faraday-follow_redirects-0.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tisba/faraday-follow-redirects
COMMENT=	FaradayMiddleware::FollowRedirects for Faraday 2.x
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.0<3:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

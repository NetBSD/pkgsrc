# $NetBSD: Makefile,v 1.35 2024/02/04 06:51:49 taca Exp $

DISTNAME=	faraday-2.9.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http>=2.0<3.2:../../www/ruby-faraday-net_http
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.4:../../devel/ruby-ruby2_keywords

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

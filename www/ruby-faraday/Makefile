# $NetBSD: Makefile,v 1.43 2025/11/03 05:56:28 taca Exp $

DISTNAME=	faraday-2.14.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http>=2.0<3.5:../../www/ruby-faraday-net_http

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

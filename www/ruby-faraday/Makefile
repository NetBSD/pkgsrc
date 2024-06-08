# $NetBSD: Makefile,v 1.36 2024/06/08 16:16:37 taca Exp $

DISTNAME=	faraday-2.9.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http>=2.0<3.2:../../www/ruby-faraday-net_http

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

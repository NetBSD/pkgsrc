# $NetBSD: Makefile,v 1.1 2023/01/09 07:43:48 taca Exp $

DISTNAME=	faraday-1.10.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/faraday/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday-em_http>=1.0<2:../../www/ruby-faraday-em_http
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-em_synchrony>=1.0<2:../../www/ruby-faraday-em_synchrony
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-excon1>=1.1<2:../../www/ruby-faraday-excon1
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-httpclient1>=1.0<2:../../www/ruby-faraday-httpclient1
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-multipart>=1.0<2:../../www/ruby-faraday-multipart
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http1>=1.0<2:../../www/ruby-faraday-net_http1
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http_persistent1>=1.1<2:../../www/ruby-faraday-net_http_persistent1
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-patron1>=1.0<2:../../www/ruby-faraday-patron1
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-rack1>=1.0<2:../../www/ruby-faraday-rack1
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-retry1>=1.0<2:../../www/ruby-faraday-retry1
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.4:../../devel/ruby-ruby2_keywords

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

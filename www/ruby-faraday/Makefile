# $NetBSD: Makefile,v 1.23 2021/06/03 14:35:12 taca Exp $

DISTNAME=	faraday-1.4.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday
COMMENT=	HTTP/REST API client library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday-excon>=1.1<2:../../www/ruby-faraday-excon
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http>=1.0<2:../../www/ruby-faraday-net_http
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-net_http_persistent>=1.1<2:../../www/ruby-faraday-net_http_persistent

DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=1.2:../../www/ruby-multipart-post
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2_keywords>=0.0.4:../../devel/ruby-ruby2_keywords

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

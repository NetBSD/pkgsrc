# $NetBSD: Makefile,v 1.15 2018/04/29 14:58:29 tsutsui Exp $
#

DISTNAME=	http-3.3.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/httprb/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0<0.7:../../www/ruby-http_parser.rb
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0<2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-http-form_data>=2.0.0<3.0:../../www/ruby-http-form_data

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

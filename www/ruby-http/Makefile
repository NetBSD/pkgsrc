# $NetBSD: Makefile,v 1.13 2017/06/05 15:32:15 taca Exp $
#

DISTNAME=	http-2.2.2
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/tarcieri/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0<0.7:../../www/ruby-http_parser.rb
DEPENDS+=	${RUBY_PKGPREFIX}-http-form_data>=1.0.1<1.1:../../www/ruby-http-form_data
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0<2:../../www/ruby-http-cookie

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

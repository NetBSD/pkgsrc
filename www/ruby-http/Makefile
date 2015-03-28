# $NetBSD: Makefile,v 1.5 2015/03/28 04:32:15 taca Exp $
#

DISTNAME=	http-0.7.3
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/tarcieri/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0<0.7:../../www/ruby-http_parser.rb
DEPENDS+=	${RUBY_PKGPREFIX}-http-form_data>=1.0.0<1.1:../../www/ruby-http-form_data

RUBY_VERSION_SUPPORTED=	200 193 21
USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

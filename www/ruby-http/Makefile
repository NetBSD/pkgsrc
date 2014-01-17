# $NetBSD: Makefile,v 1.1 2014/01/17 13:22:51 obache Exp $
#

DISTNAME=	http-0.5.0
CATEGORIES=	www

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/tarcieri/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-http_parser.rb>=0.6.0:../../www/ruby-http_parser.rb

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.17 2023/08/05 19:33:00 tsutsui Exp $
#

DISTNAME=	http-4.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/httprb/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-http-parser>=1.2.0<1.3:../../www/ruby-http-parser
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0<2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-http-form_data>=2.2<3.0:../../www/ruby-http-form_data

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

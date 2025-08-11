# $NetBSD: Makefile,v 1.18 2025/08/11 11:56:55 ryoon Exp $
#

DISTNAME=	http-5.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/httprb/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.8<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0<2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-http-form_data>=2.2<3.0:../../www/ruby-http-form_data
DEPENDS+=	${RUBY_PKGPREFIX}-llhttp-ffi>=0.5.0:../../www/ruby-llhttp-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

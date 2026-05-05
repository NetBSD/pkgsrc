# $NetBSD: Makefile,v 1.20 2026/05/05 13:44:56 taca Exp $
#

DISTNAME=	http-6.0.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/httprb/http
COMMENT=	Simple Ruby DSL for making HTTP requests
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0<2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-llhttp>=0.6.1<0.7:../../www/ruby-llhttp

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

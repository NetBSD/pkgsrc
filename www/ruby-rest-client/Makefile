# $NetBSD: Makefile,v 1.9 2020/03/20 17:48:25 taca Exp $

DISTNAME=	rest-client-2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rest-client/rest-client
COMMENT=	Simple HTTP and REST client for Ruby inspired by Sinatra
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-http-accept>=1.0.2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0.2<2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.0<4.0:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-netrc>=0.8<1:../../net/ruby-netrc

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	http-accept>=1.0.2


.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

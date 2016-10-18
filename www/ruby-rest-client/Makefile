# $NetBSD: Makefile,v 1.5 2016/10/18 16:08:35 taca Exp $

DISTNAME=	rest-client-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/archiloque/rest-client
COMMENT=	Simple HTTP and REST client for Ruby inspired by Sinatra
LICENSE=        mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.0<4.0:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-netrc>=0.7<1:../../net/ruby-netrc
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0.2<2:../../www/ruby-http-cookie

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2015/03/28 04:12:16 taca Exp $

DISTNAME=	rest-client-1.8.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/archiloque/rest-client
COMMENT=	Simple HTTP and REST client for Ruby inspired by Sinatra
LICENSE=        mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16<3.0:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-netrc>=0.7<1:../../net/ruby-netrc
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0.2<2:../../www/ruby-http-cookie

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

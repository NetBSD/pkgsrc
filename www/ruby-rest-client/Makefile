# $NetBSD: Makefile,v 1.2 2015/03/13 17:36:10 taca Exp $

DISTNAME=	rest-client-1.7.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/archiloque/rest-client
COMMENT=	Simple HTTP and REST client for Ruby inspired by Sinatra
LICENSE=        mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16<3.0:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-netrc>=0.7<1:../../net/ruby-netrc

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

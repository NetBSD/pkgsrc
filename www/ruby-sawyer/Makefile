# $NetBSD: Makefile,v 1.1 2015/12/14 13:53:27 taca Exp $

DISTNAME=	sawyer-0.6.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/sawyer
COMMENT=	Secret User Agent of HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday<0.10:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3.5:../../net/ruby-addressable

OVERRIDE_GEMSPEC+=	addressable>=2.3.5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2017/02/05 00:41:57 tsutsui Exp $

DISTNAME=	sawyer-0.8.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/sawyer
COMMENT=	Secret User Agent of HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.8<1.0:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3.5:../../net/ruby-addressable

OVERRIDE_GEMSPEC+=	addressable>=2.3.5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

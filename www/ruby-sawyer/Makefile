# $NetBSD: Makefile,v 1.4 2022/08/25 01:48:08 taca Exp $

DISTNAME=	sawyer-0.9.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/sawyer
COMMENT=	Secret User Agent of HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=0.8:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3.5:../../net/ruby-addressable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

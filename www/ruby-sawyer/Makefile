# $NetBSD: Makefile,v 1.7 2025/11/03 07:01:53 taca Exp $

DISTNAME=	sawyer-0.9.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/sawyer
COMMENT=	Secret User Agent of HTTP
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3.5:../../net/ruby-addressable
# ruby-sawyer used by ruby-octokit{,4} with ruby-faraday{,1} and
# dependencies are in ruby-octokit{,4} not here to make things simple.
# DEPENDS+=	${RUBY_PKGPREFIX}-faraday{,1}>=0.8:../../www/ruby-faraday

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

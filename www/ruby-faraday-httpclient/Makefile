# $NetBSD: Makefile,v 1.3 2025/08/11 15:32:58 taca Exp $

DISTNAME=	faraday-httpclient-2.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-httpclient
COMMENT=	Faraday adapter for HTTPClient
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-httpclient>=2.2:../../www/ruby-httpclient

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2023/01/09 12:47:03 taca Exp $

DISTNAME=	faraday-httpclient-2.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-httpclient
COMMENT=	Faraday adapter for HTTPClient
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-httpclient>=2.2:../../www/ruby-httpclient

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

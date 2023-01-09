# $NetBSD: Makefile,v 1.1 2023/01/09 07:28:37 taca Exp $

DISTNAME=	faraday-httpclient-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/httpclient/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-httpclient
COMMENT=	Faraday adapter for HTTPClient
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

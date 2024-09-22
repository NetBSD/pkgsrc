# $NetBSD: Makefile,v 1.2 2024/09/22 08:14:12 taca Exp $

DISTNAME=	faraday-net_http-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/net_http/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-net_http
COMMENT=	Faraday adapter for Net::HTTP
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

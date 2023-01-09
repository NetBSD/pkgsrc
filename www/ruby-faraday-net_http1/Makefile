# $NetBSD: Makefile,v 1.1 2023/01/09 07:30:42 taca Exp $

DISTNAME=	faraday-net_http-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/net_http/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-net_http
COMMENT=	Faraday adapter for Net::HTTP
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

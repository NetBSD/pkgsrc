# $NetBSD: Makefile,v 1.1 2023/01/09 07:38:58 taca Exp $

DISTNAME=	faraday-rack-1.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-rack/&1/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-rack
COMMENT=	Faraday adapter for Rack
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2025/11/03 05:59:51 taca Exp $

DISTNAME=	faraday-excon-2.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/excon/faraday-excon
COMMENT=	Faraday adapter for Excon
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-excon>=1.0.0:../../www/ruby-excon
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.11:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2023/01/09 12:44:21 taca Exp $

DISTNAME=	faraday-excon-2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-excon
COMMENT=	Faraday adapter for Excon
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-excon>=0.27.4:../../www/ruby-excon
DEPENDS+=	${RUBY_PKGPREFIX}-faraday>=2.0<3:../../www/ruby-faraday

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

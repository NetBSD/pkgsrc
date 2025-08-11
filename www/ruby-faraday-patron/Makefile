# $NetBSD: Makefile,v 1.3 2025/08/11 15:38:12 taca Exp $

DISTNAME=	faraday-patron-2.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostisland/faraday-patron
COMMENT=	Faraday adapter for Patron
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-patron>=0.4.2:../../www/ruby-patron

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2025/11/03 06:33:35 taca Exp $

DISTNAME=	propshaft-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/propshaft/&11/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/propshaft
COMMENT=	Deliver assets for Rails version 1.1.x
LICENSE=	mit

#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
#DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

#
# This pacakge is for redmine61
#
RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2026/04/19 14:41:11 taca Exp $

DISTNAME=	propshaft-1.3.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/propshaft
COMMENT=	Deliver assets for Rails
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

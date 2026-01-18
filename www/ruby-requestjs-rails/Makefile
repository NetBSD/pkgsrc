# $NetBSD: Makefile,v 1.2 2026/01/18 15:36:28 taca Exp $

DISTNAME=	requestjs-rails-0.0.14
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/requestjs-rails
COMMENT=	Tiny Fetch API wrapper to handle CSRF token
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

#
# This pacakge is for redmine61
#
RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2025/11/03 06:55:33 taca Exp $

DISTNAME=	requestjs-rails-0.0.13
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

# $NetBSD: Makefile,v 1.1 2025/11/03 07:09:02 taca Exp $

DISTNAME=	stimulus-rails-1.3.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hotwired/stimulus-rails
COMMENT=	Modest JavaScript framework for the HTML you already have
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

#
# This pacakge is for redmine61
#
RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

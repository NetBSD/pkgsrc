# $NetBSD: Makefile,v 1.1 2025/11/03 05:49:50 taca Exp $

DISTNAME=	doorkeeper-5.8.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doorkeeper-gem/doorkeeper
COMMENT=	OAuth 2 provider for Rails and Grape
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

#
# This pacakge is for redmine61
#
RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

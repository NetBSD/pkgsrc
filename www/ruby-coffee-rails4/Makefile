# $NetBSD: Makefile,v 1.1 2020/03/21 16:04:15 taca Exp $

DISTNAME=	coffee-rails-4.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails-/rails${RUBY_RAILS}-/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/coffee-rails
COMMENT=	Coffee Script adapter for the Rails asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script>=2.2.0:../../lang/ruby-coffee-script
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	51

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

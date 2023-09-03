# $NetBSD: Makefile,v 1.4 2023/09/03 02:11:53 taca Exp $

DISTNAME=	coffee-rails-5.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails-/rails${RUBY_RAILS}-/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/coffee-rails
COMMENT=	Coffee Script adapter for the Rails asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script>=2.2.0:../../lang/ruby-coffee-script
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	52 60 61

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

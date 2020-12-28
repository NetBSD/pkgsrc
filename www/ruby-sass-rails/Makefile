# $NetBSD: Makefile,v 1.5 2020/12/28 08:20:48 taca Exp $

DISTNAME=	sass-rails-6.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails-/rails${RUBY_RAILS}-/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sass-rails/
COMMENT=	Sass adapter for the Rails asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sassc-rails>=2.1.1:../../www/ruby-sassc-rails

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

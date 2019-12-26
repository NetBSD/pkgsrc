# $NetBSD: Makefile,v 1.2 2019/12/26 05:45:33 taca Exp $

DISTNAME=	sass-rails-5.0.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rails-/rails${RUBY_RAILS}-/}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sass-rails/
COMMENT=	Sass adapter for the Rails asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.1<4:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets-rails>=3:../../misc/ruby-sprockets-rails
DEPENDS+=	${RUBY_PKGPREFIX}-tilt1>=1.3<3:../../textproc/ruby-tilt1

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	42 51

OVERRIDE_GEMSPEC=	sprockets-rails>=3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2019/12/27 03:17:53 taca Exp $

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
RUBY_VERSIONS_ACCEPTED=	25 26

OVERRIDE_GEMSPEC=	sprockets-rails>=3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

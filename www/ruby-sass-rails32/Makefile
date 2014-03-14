# $NetBSD: Makefile,v 1.4 2014/03/14 13:22:11 taca Exp $

DISTNAME=	sass-rails-3.2.6
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sass-rails/
COMMENT=	Sass adapter for the Rails asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.1.10:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3:../../textproc/ruby-tilt

RUBY_RAILS_SUPPORTED=	32

OVERRIDE_GEMSPEC+=	tilt>=1.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

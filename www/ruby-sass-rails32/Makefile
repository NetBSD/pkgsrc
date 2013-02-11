# $NetBSD: Makefile,v 1.3 2013/02/11 14:51:28 taca Exp $

DISTNAME=	sass-rails-3.2.6
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sass-rails/
COMMENT=	Sass adapter for the Rails asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.1.10:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3<1.4:../../textproc/ruby-tilt

RUBY_RAILS_SUPPORTED=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

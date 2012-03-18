# $NetBSD: Makefile,v 1.1.1.1 2012/03/18 07:13:47 taca Exp $

DISTNAME=	sass-rails-3.1.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sass-rails/tree/3-1-stable
COMMENT=	Sass adapter for the Rails asset pipeline
LICENSE=	mit

#DEPENDS+=	${RUBY_ACTIONPACK_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.1.10<3.2:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=1.3.2<1.4:../../textproc/ruby-tilt

RUBY_RAILS_SUPPORTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

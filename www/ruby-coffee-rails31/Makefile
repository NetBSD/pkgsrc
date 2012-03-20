# $NetBSD: Makefile,v 1.1.1.1 2012/03/20 13:15:44 taca Exp $

DISTNAME=	coffee-rails-3.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/coffee-rails/tree/3-1-stable/
COMMENT=	Coffee Script adapter for the Rails 3.1 asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script>=2.2.0:../../lang/ruby-coffee-script
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_SUPPORTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

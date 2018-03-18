# $NetBSD: Makefile,v 1.3 2018/03/18 14:21:22 taca Exp $

DISTNAME=	coffee-rails-3.2.2
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/coffee-rails/tree/3-1-stable/
COMMENT=	Coffee Script adapter for the Rails 3.2 asset pipeline
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script>=2.2.0:../../lang/ruby-coffee-script
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	32

OVERRIDE_GEMSPEC+=	railties~>3.2.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

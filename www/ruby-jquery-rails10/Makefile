# $NetBSD: Makefile,v 1.2 2012/09/16 15:57:20 taca Exp $

DISTNAME=	jquery-rails-1.0.19
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/jquery-rails
COMMENT=	jQuery support for Rails 3.0
LICENSE=	mit

RUBY_RAILS_SUPPORTED=	3

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<1:../../devel/ruby-thor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

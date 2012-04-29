# $NetBSD: Makefile,v 1.2 2012/04/29 15:49:43 taca Exp $

DISTNAME=	jquery-rails-2.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/jquery-rails
COMMENT=	jQuery support for Rails 3.2
LICENSE=	mit

RUBY_RAILS_SUPPORTED=	32

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<1:../../devel/ruby-thor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

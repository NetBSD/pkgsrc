# $NetBSD: Makefile,v 1.3 2012/09/16 14:36:20 taca Exp $

DISTNAME=	jquery-rails-2.1.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/jquery-rails
COMMENT=	jQuery support for Rails
LICENSE=	mit

RUBY_RAILS_SUPPORTED=	31 32

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<1:../../devel/ruby-thor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

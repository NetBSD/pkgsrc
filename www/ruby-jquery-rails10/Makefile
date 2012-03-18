# $NetBSD: Makefile,v 1.1.1.1 2012/03/18 07:02:55 taca Exp $

DISTNAME=	jquery-rails-1.0.19
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/jquery-rails
COMMENT=	jQuery support for Rails 3.0 and 3.1
LICENSE=	mit

RUBY_RAILS_SUPPORTED=	3 31

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<1:../../devel/ruby-thor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2012/12/17 15:29:32 taca Exp $

DISTNAME=	jquery-rails-2.1.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/jquery-rails
COMMENT=	jQuery support for Rails
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<1:../../devel/ruby-thor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

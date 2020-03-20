# $NetBSD: Makefile,v 1.14 2020/03/20 15:13:58 taca Exp $

DISTNAME=	jquery-rails-4.3.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/jquery-rails
COMMENT=	Rails jQuery support
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<2:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=2.0:../../textproc/ruby-rails-dom-testing

RUBY_RAILS_ACCEPTED=	52 51

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

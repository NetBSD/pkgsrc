# $NetBSD: Makefile,v 1.13 2019/03/05 22:35:31 taca Exp $

DISTNAME=	jquery-rails-4.3.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/jquery-rails
COMMENT=	Rails jQuery support
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<2:../../devel/ruby-thor

RUBY_RAILS_ACCEPTED=

.include "../../lang/ruby/gem.mk"
.if ${RUBY_RAILS} >= 51
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing>=2.0:../../textproc/ruby-rails-dom-testing
.else
DEPENDS+=	${RUBY_PKGPREFIX}-rails-dom-testing1>=1.0:../../textproc/ruby-rails-dom-testing1
.endif
.include "../../mk/bsd.pkg.mk"

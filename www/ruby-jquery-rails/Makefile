# $NetBSD: Makefile,v 1.11 2017/06/21 15:42:11 taca Exp $

DISTNAME=	jquery-rails-3.1.4
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/jquery-rails
COMMENT=	Rails jQuery support
LICENSE=	mit

DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.14<2:../../devel/ruby-thor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

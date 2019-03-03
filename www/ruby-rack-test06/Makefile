# $NetBSD: Makefile,v 1.1 2019/03/03 14:35:21 taca Exp $

DISTNAME=	rack-test-0.6.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-test/-test06/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack 0.6
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2019/03/03 16:45:21 taca Exp $

DISTNAME=	rack-test-1.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2017/07/30 22:32:28 wiz Exp $

DISTNAME=	rack-test-0.6.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

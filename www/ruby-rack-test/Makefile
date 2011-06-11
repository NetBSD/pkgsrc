# $NetBSD: Makefile,v 1.3 2011/06/11 02:45:12 taca Exp $

DISTNAME=	rack-test-0.5.7
CATEGORIES=	www

# Note: www/ruby-actionpack3 needs ruby-rack-test<0.6.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

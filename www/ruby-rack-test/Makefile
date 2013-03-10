# $NetBSD: Makefile,v 1.6 2013/03/10 09:17:18 taca Exp $

DISTNAME=	rack-test-0.6.2
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.0:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

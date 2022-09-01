# $NetBSD: Makefile,v 1.11 2022/09/01 13:58:57 taca Exp $

DISTNAME=	rack-test-2.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

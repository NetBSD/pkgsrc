# $NetBSD: Makefile,v 1.2 2012/09/16 16:00:34 taca Exp $

DISTNAME=	rack-test-0.5.7
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/brynary/rack-test
COMMENT=	Simple testing API built on Rack
LICENSE=	mit

# This package is for Ruby on Rails 3.0.x.
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0<1.3:../../www/ruby-rack12

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

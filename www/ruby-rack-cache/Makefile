# $NetBSD: Makefile,v 1.7 2017/03/20 15:56:11 taca Exp $

DISTNAME=	rack-cache-1.7.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	HTTP Caching for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=0.4:../../www/ruby-rack14

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

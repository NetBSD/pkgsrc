# $NetBSD: Makefile,v 1.3 2014/03/14 19:02:56 taca Exp $

DISTNAME=	http_router-0.11.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/joshbuddy/http_router/
COMMENT=	Kick-ass HTTP router for use in Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-url_mount>=0.2.1<0.3:../../www/ruby-url_mount

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

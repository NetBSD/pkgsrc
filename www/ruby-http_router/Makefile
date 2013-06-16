# $NetBSD: Makefile,v 1.2 2013/06/16 09:36:23 obache Exp $

DISTNAME=	http_router-0.11.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/joshbuddy/http_router/
COMMENT=	Kick-ass HTTP router for use in Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-url_mount>=0.2.1<0.3:../../www/ruby-url_mount

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

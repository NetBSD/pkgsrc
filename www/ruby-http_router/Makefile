# $NetBSD: Makefile,v 1.1 2013/02/11 12:43:13 taca Exp $

DISTNAME=	http_router-0.10.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/joshbuddy/http_router/
COMMENT=	Kick-ass HTTP router for use in Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-url_mount>=0.2.1<0.3:../../www/ruby-url_mount

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2017/06/05 03:29:38 taca Exp $

DISTNAME=	http_router-0.11.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joshbuddy/http_router/
COMMENT=	Kick-ass HTTP router for use in Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-url_mount>=0.2.1<0.3:../../www/ruby-url_mount

RUBY_VERSIONS_ACCEPTED=	23 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

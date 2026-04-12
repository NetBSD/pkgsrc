# $NetBSD: Makefile,v 1.4 2026/04/12 15:31:10 taca Exp $

DISTNAME=	rack-session-2.1.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-session
COMMENT=	Session implementation for Rack
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=3.0.0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2017/06/06 11:12:05 jperkin Exp $

DISTNAME=	rack-contrib-1.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-contrib/
COMMENT=	Contributed Rack Middleware and Utilities
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0:../../www/ruby-rack

RUBY_VERSIONS_ACCEPTED=	22 23	# www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

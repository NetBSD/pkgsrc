# $NetBSD: Makefile,v 1.12 2021/01/16 13:12:11 taca Exp $

DISTNAME=	rack-contrib-2.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-contrib/
COMMENT=	Contributed Rack Middleware and Utilities
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack

USE_LANGAUGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

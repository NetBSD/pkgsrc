# $NetBSD: Makefile,v 1.10 2019/02/03 15:57:27 taca Exp $

DISTNAME=	rack-contrib-2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-contrib/
COMMENT=	Contributed Rack Middleware and Utilities
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.0:../../www/ruby-rack

USE_LANGAUGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

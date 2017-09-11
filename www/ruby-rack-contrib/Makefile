# $NetBSD: Makefile,v 1.6 2017/09/11 15:43:46 taca Exp $

DISTNAME=	rack-contrib-1.6.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rack/rack-contrib/
COMMENT=	Contributed Rack Middleware and Utilities
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.4:../../www/ruby-rack15

RUBY_VERSIONS_ACCEPTED=	22 23 24	# www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

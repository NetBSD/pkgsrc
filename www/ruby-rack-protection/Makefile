# $NetBSD: Makefile,v 1.3 2013/01/17 12:43:34 taca Exp $

DISTNAME=	rack-protection-1.3.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rkh/rack-protection
COMMENT=	Protection for against typical web attacks for Rack application
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0:../../www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

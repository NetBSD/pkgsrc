# $NetBSD: Makefile,v 1.1 2015/03/13 16:32:47 taca Exp $

DISTNAME=	compass-core-1.0.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/reference/compass/
COMMENT=	Compass core stylesheet library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass<3.5:../../www/ruby-sass
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

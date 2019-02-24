# $NetBSD: Makefile,v 1.2 2019/02/24 16:24:55 taca Exp $

DISTNAME=	compass-core-1.0.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compass-style.org/reference/compass/
COMMENT=	Compass core stylesheet library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass34<3.5:../../www/ruby-sass34
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

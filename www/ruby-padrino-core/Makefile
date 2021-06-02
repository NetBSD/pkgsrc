# $NetBSD: Makefile,v 1.10 2021/06/02 15:09:52 taca Exp $

DISTNAME=	padrino-core-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Padrino framework core
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-support>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-support
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=2.0.0:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0<2:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

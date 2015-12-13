# $NetBSD: Makefile,v 1.7 2015/12/13 15:52:14 taca Exp $

DISTNAME=	padrino-core-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Padrino framework core
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-support>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-support
DEPENDS+=	${RUBY_PKGPREFIX}-mustermann19>=0.4.0:../../www/ruby-mustermann19
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.5.0:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.4.6<1.5:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.18:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

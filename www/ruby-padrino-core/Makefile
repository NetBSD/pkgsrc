# $NetBSD: Makefile,v 1.6 2015/02/04 14:54:53 taca Exp $

DISTNAME=	padrino-core-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Padrino framework core
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-support>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-support
DEPENDS+=	${RUBY_PKGPREFIX}-http_router>=0.11.0<0.12:../../www/ruby-http_router
DEPENDS+=	${RUBY_PKGPREFIX}-rack-protection>=1.5.0:../../www/ruby-rack-protection
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra>=1.4.2<1.5:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.18:../../devel/ruby-thor

CONFLICTS+=	ruby[1-9][0-9][0-9]-padrino-core-[0-9]*

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

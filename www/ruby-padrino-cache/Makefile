# $NetBSD: Makefile,v 1.8 2020/05/18 14:54:18 taca Exp $

DISTNAME=	padrino-cache-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Page and fragment caching for Padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-helpers>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-moneta>=1.1.0:../../databases/ruby-moneta

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

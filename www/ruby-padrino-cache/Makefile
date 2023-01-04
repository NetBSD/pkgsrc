# $NetBSD: Makefile,v 1.10 2023/01/04 15:33:36 taca Exp $

DISTNAME=	padrino-cache-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Page and fragment caching for Padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-helpers>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-moneta>=1.1.0:../../databases/ruby-moneta

USE_LANGUAGES=	# empty

OVERRIDE_GEMSPEC+=	moneta>=1.1.0

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

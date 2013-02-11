# $NetBSD: Makefile,v 1.1 2013/02/11 14:30:57 taca Exp $

DISTNAME=	padrino-cache-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Page and fragment caching for Padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2015/06/04 00:10:12 taca Exp $

DISTNAME=	padrino-cache-${RUBY_PADRINO_VERS}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Page and fragment caching for Padrino
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-padrino-helpers>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-helpers
DEPENDS+=	${RUBY_PKGPREFIX}-moneta>=0.7.0<1:../../databases/ruby-moneta

OVERRIDE_GEMSPEC+=	moneta>=0.7.0

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

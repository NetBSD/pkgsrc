# $NetBSD: Makefile,v 1.2 2015/12/13 15:52:14 taca Exp $

DISTNAME=	padrino-gen-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Generators for easily creating and building padrino applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.0<2:../../misc/ruby-bundler

RUBYGEM_OPTIONS+=	--format-executable

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

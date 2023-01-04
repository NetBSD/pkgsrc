# $NetBSD: Makefile,v 1.8 2023/01/04 15:33:36 taca Exp $

DISTNAME=	padrino-gen-${RUBY_PADRINO_VERS}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Generators for easily creating and building padrino applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core
# bundlerd with ruby*-base
#DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.0:../../misc/ruby-bundler

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

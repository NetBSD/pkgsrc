# $NetBSD: Makefile,v 1.4 2019/03/05 07:52:19 taca Exp $

DISTNAME=	padrino-gen-${RUBY_PADRINO_VERS}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${RUBY_PADRINO_SITE}
COMMENT=	Generators for easily creating and building padrino applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-padrino-core>=${RUBY_PADRINO_VERS}:../../www/ruby-padrino-core

RUBYGEM_OPTIONS+=	--format-executable

.include "../../www/ruby-padrino/Makefile.common"
.include "../../lang/ruby/gem.mk"
.if ${RUBY_VER} != 26
DEPENDS+=	${RUBY_PKGPREFIX}-bundler1>=1.0<2:../../misc/ruby-bundler1
.endif
.include "../../mk/bsd.pkg.mk"

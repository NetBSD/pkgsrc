# $NetBSD: Makefile,v 1.27 2025/05/19 15:49:23 taca Exp $

DISTNAME=	sass-3.7.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sass-lang.com/
COMMENT=	Powerful, but elegant CSS compiler that makes CSS fun again
LICENSE=	mit

CONFLICTS+=	${RUBY_PKGPREFIX}-sass-embedded-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-sass-listen>=4.0.0<4.1:../../www/ruby-sass-listen

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

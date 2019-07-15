# $NetBSD: Makefile,v 1.25 2019/07/15 16:14:29 nia Exp $

DISTNAME=	sass-3.7.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sass-lang.com/
COMMENT=	Powerful, but elegant CSS compiler that makes CSS fun again
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass-listen>=4.0.0<4.1:../../www/ruby-sass-listen

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

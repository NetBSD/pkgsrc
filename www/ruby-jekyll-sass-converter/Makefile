# $NetBSD: Makefile,v 1.8 2025/06/15 16:23:26 taca Exp $

DISTNAME=	jekyll-sass-converter-3.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass-embedded>=1.75<2:../../www/ruby-sass-embedded

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

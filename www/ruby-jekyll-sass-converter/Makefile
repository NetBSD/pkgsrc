# $NetBSD: Makefile,v 1.7 2022/09/01 14:51:15 taca Exp $

DISTNAME=	jekyll-sass-converter-2.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sassc>=2.0.1:../../www/ruby-sassc

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2015/03/13 16:47:01 taca Exp $

DISTNAME=	jekyll-sass-converter-1.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.2<4:../../www/ruby-sass

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

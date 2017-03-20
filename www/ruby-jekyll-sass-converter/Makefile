# $NetBSD: Makefile,v 1.3 2017/03/20 16:40:09 taca Exp $

DISTNAME=	jekyll-sass-converter-1.5.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.4<4:../../www/ruby-sass

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

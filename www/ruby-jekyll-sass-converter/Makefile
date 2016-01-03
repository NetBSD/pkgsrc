# $NetBSD: Makefile,v 1.2 2016/01/03 08:19:17 taca Exp $

DISTNAME=	jekyll-sass-converter-1.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.4<4:../../www/ruby-sass

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2018/03/13 17:08:37 taca Exp $

DISTNAME=	jekyll-sass-converter-1.5.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sass>=3.4<4:../../www/ruby-sass

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

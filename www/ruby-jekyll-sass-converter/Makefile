# $NetBSD: Makefile,v 1.5 2019/10/05 04:58:42 ryoon Exp $

DISTNAME=	jekyll-sass-converter-2.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-sass-converter
COMMENT=	Basic Sass converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sassc>=2.0.1<3:../../www/ruby-sassc

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

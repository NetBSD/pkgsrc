# $NetBSD: Makefile,v 1.1 2017/04/22 17:09:17 taca Exp $

DISTNAME=	minima-2.1.1
PKGNAME=	${RUBY_PKGPREFIX}-jekyll-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/minima
COMMENT=	Beautiful, minimal and default theme for Jekyll
LICENSE=	mit

#
# gemspec says dependency, but this package is really part of jekyll.
#DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=3.3<4:../../www/ruby-jekyll

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

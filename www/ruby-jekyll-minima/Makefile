# $NetBSD: Makefile,v 1.8 2020/03/15 21:13:35 wiz Exp $

DISTNAME=	minima-2.5.1
PKGNAME=	${RUBY_PKGPREFIX}-jekyll-${DISTNAME}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/minima
COMMENT=	Beautiful, minimal and default theme for Jekyll
LICENSE=	mit

#
# gemspec says dependency, but this package is really part of jekyll.
#DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=3.5<4:../../www/ruby-jekyll
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-feed>=0.9<1:../../www/ruby-jekyll-feed
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-seo-tag>=2.1<3:../../www/ruby-jekyll-seo-tag

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2018/03/13 17:32:46 taca Exp $

DISTNAME=	jekyll-feed-0.9.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-feed
COMMENT=	Jekyll plugin to generate an Atom feed of your Jekyll posts
LICENSE=	mit

#
# gemspec says dependency, but this package is really part of jekyll.
#DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=3.3<4:../../www/ruby-jekyll

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

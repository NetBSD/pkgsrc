# $NetBSD: Makefile,v 1.8 2020/03/15 21:13:35 wiz Exp $

DISTNAME=	jekyll-feed-0.12.1
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

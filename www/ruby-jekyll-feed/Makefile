# $NetBSD: Makefile,v 1.10 2020/09/14 15:33:11 taca Exp $

DISTNAME=	jekyll-feed-0.15.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-feed
COMMENT=	Jekyll plugin to generate an Atom feed of your Jekyll posts
LICENSE=	mit

# gemspec says dependency, but this package is really part of jekyll.
#DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=3.7:../../www/ruby-jekyll

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

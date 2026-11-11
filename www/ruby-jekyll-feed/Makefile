# $NetBSD: Makefile,v 1.13.32.1 2026/11/11 10:48:06 maya Exp $

DISTNAME=	jekyll-feed-0.18.0
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

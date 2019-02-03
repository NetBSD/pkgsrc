# $NetBSD: Makefile,v 1.5 2019/02/03 13:45:07 taca Exp $

DISTNAME=	jekyll-feed-0.11.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-feed
COMMENT=	Jekyll plugin to generate an Atom feed of your Jekyll posts
LICENSE=	mit

#
# gemspec says dependency, but this package is really part of jekyll.
#DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=3.3<4:../../www/ruby-jekyll

RUBY_VERSIONS_ACCEPTED=	23 24 25 26

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

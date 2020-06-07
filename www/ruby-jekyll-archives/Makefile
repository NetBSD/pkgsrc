# $NetBSD: Makefile,v 1.10 2020/06/07 15:31:47 taca Exp $

DISTNAME=	jekyll-archives-2.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-archives/
COMMENT=	Automatically generates post archives by dates, tags, and categories
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=2.4:../../www/ruby-jekyll

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

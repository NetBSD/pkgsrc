# $NetBSD: Makefile,v 1.11 2023/04/29 13:47:07 wiz Exp $

DISTNAME=	jekyll-archives-2.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-archives/
COMMENT=	Automatically generates post archives by dates, tags, and categories
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=2.4:../../www/ruby-jekyll

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

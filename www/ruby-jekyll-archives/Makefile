# $NetBSD: Makefile,v 1.9 2020/03/15 21:13:35 wiz Exp $

DISTNAME=	jekyll-archives-2.1.1
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-archives/
COMMENT=	Automatically generates post archives by dates, tags, and categories
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-jekyll>=2.4:../../www/ruby-jekyll

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2015/12/13 16:51:29 taca Exp $

DISTNAME=	jekyll-gist-1.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-gist/
COMMENT=	Liquid tag for displaying GitHub Gists in Jekyll sites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-octokit>=4.2<5:../../devel/ruby-octokit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

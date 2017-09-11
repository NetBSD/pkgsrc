# $NetBSD: Makefile,v 1.5 2017/09/11 16:03:17 taca Exp $

DISTNAME=	jekyll-gist-1.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-gist/
COMMENT=	Liquid tag for displaying GitHub Gists in Jekyll sites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-octokit>=4.2<5:../../devel/ruby-octokit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

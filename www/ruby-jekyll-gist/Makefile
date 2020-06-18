# $NetBSD: Makefile,v 1.7 2020/06/18 16:41:11 taca Exp $

DISTNAME=	jekyll-gist-1.5.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-gist/
COMMENT=	Liquid tag for displaying GitHub Gists in Jekyll sites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-octokit>=4.2<5:../../devel/ruby-octokit

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run

REPLACE_BASH+=	script/bootstrap script/cibuild script/fmt script/release

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

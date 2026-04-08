# $NetBSD: Makefile,v 1.10 2026/04/08 14:29:35 taca Exp $

DISTNAME=	jekyll-gist-1.5.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-gist/
COMMENT=	Liquid tag for displaying GitHub Gists in Jekyll sites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-octokit4>=4.2<5:../../devel/ruby-octokit4

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run

RUBY_VERSIONS_ACCEPTED=	33 34

REPLACE_BASH+=	script/bootstrap script/cibuild script/fmt script/release

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

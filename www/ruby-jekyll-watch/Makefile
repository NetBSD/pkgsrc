# $NetBSD: Makefile,v 1.7 2017/06/18 13:48:54 taca Exp $

DISTNAME=	jekyll-watch-1.5.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-watch
COMMENT=	Rebuild your Jekyll site when a file changes
LICENSE=	mit

# restricted by ruby-dep and ruby-listen
RUBY_VERSIONS_ACCEPTED= 22 23 24

DEPENDS+=	${RUBY_PKGPREFIX}-listen>=3.0<4:../../sysutils/ruby-listen

OVERRIDE_GEMSPEC+=      listen>=3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

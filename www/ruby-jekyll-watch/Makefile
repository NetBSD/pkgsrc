# $NetBSD: Makefile,v 1.1 2015/03/13 16:47:46 taca Exp $

DISTNAME=	jekyll-watch-1.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-watch
COMMENT=	Rebuild your Jekyll site when a file changes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-listen>=2.7<3:../../sysutils/ruby-listen

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

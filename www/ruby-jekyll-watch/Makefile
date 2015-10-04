# $NetBSD: Makefile,v 1.2 2015/10/04 13:28:41 taca Exp $

DISTNAME=	jekyll-watch-1.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-watch
COMMENT=	Rebuild your Jekyll site when a file changes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-listen>=3.0<4:../../sysutils/ruby-listen

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

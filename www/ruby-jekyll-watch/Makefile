# $NetBSD: Makefile,v 1.3 2016/03/15 16:12:13 taca Exp $

DISTNAME=	jekyll-watch-1.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-watch
COMMENT=	Rebuild your Jekyll site when a file changes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-listen>=3.0<4:../../sysutils/ruby-listen

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

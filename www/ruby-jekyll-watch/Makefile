# $NetBSD: Makefile,v 1.10 2019/11/04 22:10:14 rillig Exp $

DISTNAME=	jekyll-watch-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-watch
COMMENT=	Rebuild your Jekyll site when a file changes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-listen>=3.0<4:../../sysutils/ruby-listen

OVERRIDE_GEMSPEC+=	listen>=3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

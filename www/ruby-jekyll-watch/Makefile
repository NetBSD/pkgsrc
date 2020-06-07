# $NetBSD: Makefile,v 1.11 2020/06/07 15:40:14 taca Exp $

DISTNAME=	jekyll-watch-2.2.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-watch
COMMENT=	Rebuild your Jekyll site when a file changes
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-listen>=3.0<4:../../sysutils/ruby-listen

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	listen>=3.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

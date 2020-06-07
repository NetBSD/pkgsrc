# $NetBSD: Makefile,v 1.4 2020/06/07 15:33:23 taca Exp $

DISTNAME=	jekyll-coffeescript-2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-coffeescript
COMMENT=	CoffeeScript converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script>=2.2<3:../../lang/ruby-coffee-script

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	coffee-script-source>=1.12

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

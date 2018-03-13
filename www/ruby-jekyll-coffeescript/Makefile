# $NetBSD: Makefile,v 1.3 2018/03/13 17:46:30 taca Exp $

DISTNAME=	jekyll-coffeescript-1.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll-coffeescript
COMMENT=	CoffeeScript converter for Jekyll
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-coffee-script>=2.2<3:../../lang/ruby-coffee-script

OVERRIDE_GEMSPEC+=	coffee-script-source>=1.11.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

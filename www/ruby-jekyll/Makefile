# $NetBSD: Makefile,v 1.1.1.1 2011/05/26 22:17:43 minskim Exp $

DISTNAME=	jekyll-0.10.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mojombo/jekyll
COMMENT=	Blog-aware, static site generator in Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-classifier>=1.3.1:../../textproc/ruby-classifier
DEPENDS+=	${RUBY_PKGPREFIX}-directory-watcher>=1.1.1:../../sysutils/ruby-directory-watcher
DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=1.9.0:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-maruku>=0.5.9:../../textproc/ruby-maruku
LICENSE=	mit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

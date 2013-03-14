# $NetBSD: Makefile,v 1.6 2013/03/14 16:21:11 taca Exp $

DISTNAME=	jekyll-0.12.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mojombo/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=2.3<3:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-classifier>=1.3.1<2:../../textproc/ruby-classifier
DEPENDS+=	${RUBY_PKGPREFIX}-directory-watcher>=1.1<2:../../sysutils/ruby-directory-watcher
DEPENDS+=	${RUBY_PKGPREFIX}-maruku>=0.5.9<1:../../textproc/ruby-maruku
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=0.14<1:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-pygments.rb>=0.3.2<0.4:../../www/ruby-pygments.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

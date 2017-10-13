# $NetBSD: Makefile,v 1.28 2017/10/13 16:52:46 taca Exp $

DISTNAME=	jekyll-3.5.2
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mojombo/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.4<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=1.0<2:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-sass-converter>=1.0<2:../../www/ruby-jekyll-sass-converter
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-watch>=1.1<2:../../www/ruby-jekyll-watch
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=1.3<2:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=4.0<5:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.3<0.4:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-pathutil>=0.9<1:../../devel/ruby-pathutil
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=1.7<2:../../www/ruby-rouge

DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0<2:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-minima>=2.1.1:../../www/ruby-jekyll-minima
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-feed>=0.9.2:../../www/ruby-jekyll-feed
DEPENDS+=       ${RUBY_PKGPREFIX}-bundler>=1.7:../../misc/ruby-bundler

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

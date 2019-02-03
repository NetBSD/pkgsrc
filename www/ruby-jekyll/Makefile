# $NetBSD: Makefile,v 1.32 2019/02/03 13:45:07 taca Exp $

DISTNAME=	jekyll-3.8.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.4<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=1.0<2:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-em-websocket>=0.5<1:../../www/ruby-em-websocket
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.7:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-sass-converter>=1.0<2:../../www/ruby-jekyll-sass-converter
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-watch>=2.0<3:../../www/ruby-jekyll-watch
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=1.14<2:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=4.0<5:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.3<0.4:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-pathutil>=0.9<1:../../devel/ruby-pathutil
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=1.7<4:../../www/ruby-rouge

DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0<2:../../textproc/ruby-safe_yaml
# below packages are not listed in gemspec
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-minima>=2.1.1:../../www/ruby-jekyll-minima
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-feed>=0.9.2:../../www/ruby-jekyll-feed
DEPENDS+=       ${RUBY_PKGPREFIX}-bundler>=1.7:../../misc/ruby-bundler

RUBY_VERSIONS_ACCEPTED=	23 24 25 26

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	i18n>=0.7

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

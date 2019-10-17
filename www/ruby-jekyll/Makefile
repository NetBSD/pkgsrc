# $NetBSD: Makefile,v 1.37 2019/10/17 16:13:17 taca Exp $

DISTNAME=	jekyll-4.0.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.4<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=1.0<2:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-em-websocket>=0.5<1:../../www/ruby-em-websocket
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-sass-converter>=2.0<3:../../www/ruby-jekyll-sass-converter
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-watch>=2.0<3:../../www/ruby-jekyll-watch
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.1<3:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm>=1.0.1<2:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=4.0<5:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.3<0.4:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-pathutil>=0.9<1:../../devel/ruby-pathutil
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=3.0<4:../../www/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0<2:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-terminal-table>=1.8<2:../../textproc/ruby-terminal-table
# below packages are not listed in gemspec
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-minima>=2.5<3:../../www/ruby-jekyll-minima
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-feed>=0.12<1:../../www/ruby-jekyll-feed

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.if ${RUBY_VER} != 26
DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.7:../../misc/ruby-bundler
.endif
.include "../../mk/bsd.pkg.mk"

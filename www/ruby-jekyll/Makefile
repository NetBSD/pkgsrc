# $NetBSD: Makefile,v 1.47 2024/02/04 08:50:04 taca Exp $

DISTNAME=	jekyll-4.3.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jekyll/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.4<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=1.0<2:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-em-websocket>=0.5<1:../../www/ruby-em-websocket
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1<2:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-sass-converter>=2.0:../../www/ruby-jekyll-sass-converter
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-watch>=2.0<3:../../www/ruby-jekyll-watch
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.3.1<3:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm>=1.0.1<2:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=4.0:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.4.0<0.5:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-pathutil>=0.9<1:../../devel/ruby-pathutil
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=3.0<5.0:../../www/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0<2:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-terminal-table>=2.0:../../textproc/ruby-terminal-table
# below packages are not listed in gemspec
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-minima>=2.5<3:../../www/ruby-jekyll-minima
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-feed>=0.12<1:../../www/ruby-jekyll-feed
DEPENDS+=	${RUBY_PKGPREFIX}-webrick>=1.7.0:../../www/ruby-webrick

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	liquid>=4.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

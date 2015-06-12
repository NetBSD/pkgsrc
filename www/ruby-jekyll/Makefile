# $NetBSD: Makefile,v 1.12 2015/06/12 22:59:26 taca Exp $

DISTNAME=	jekyll-2.5.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mojombo/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=2.6.1<2.7:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=1.3<2:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.3<0.4:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0<2:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=0.1<1:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-pygments.rb>=0.6.0<0.7:../../www/ruby-pygments.rb
DEPENDS+=	${RUBY_PKGPREFIX}-redcarpet>=3.1<4:../../textproc/ruby-redcarpet
DEPENDS+=	${RUBY_PKGPREFIX}-toml>=0.1.0<0.2:../../textproc/ruby-toml
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-paginate>=1.0<2:../../www/ruby-jekyll-paginate
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-gist>=1.0<2:../../www/ruby-jekyll-gist
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-coffeescript>=1.0<2:../../www/ruby-jekyll-coffeescript
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-sass-converter>=1.0<2:../../www/ruby-jekyll-sass-converter
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-watch>=1.1<2:../../www/ruby-jekyll-watch
DEPENDS+=	${RUBY_PKGPREFIX}-classifier-reborn>=2.0<3:../../textproc/ruby-classifier-reborn

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.23 2017/04/23 13:04:00 taca Exp $

DISTNAME=	jekyll-3.4.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mojombo/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=3.0<4:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=1.3<2:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.3<0.4:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=1.0<2:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=1.0<2:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=1.7<2:../../www/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-sass-converter>=1.0<2:../../www/ruby-jekyll-sass-converter
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-watch>=1.1<2:../../www/ruby-jekyll-watch
DEPENDS+=	${RUBY_PKGPREFIX}-pathutil>=0.9<1:../../devel/ruby-pathutil
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.4<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-minima>=2.1.1:../../www/ruby-jekyll-minima
DEPENDS+=	${RUBY_PKGPREFIX}-jekyll-feed>=0.9.2:../../www/ruby-jekyll-feed

RUBYGEM_OPTIONS+=	--format-executable

# restricted by ruby-jekyll-watch through ruby-dep and ruby-listen
RUBY_VERSIONS_ACCEPTED= 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

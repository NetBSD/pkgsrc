# $NetBSD: Makefile,v 1.19 2016/10/18 10:34:29 wiz Exp $

DISTNAME=	jekyll-3.3.0
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

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

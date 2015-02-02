# $NetBSD: Makefile,v 1.10 2015/02/02 12:35:11 jperkin Exp $

DISTNAME=	jekyll-1.2.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mojombo/jekyll
COMMENT=	Blog-aware, static site generator in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-liquid>=2.5.1<2.6:../../www/ruby-liquid
DEPENDS+=	${RUBY_PKGPREFIX}-classifier>=1.3.2<2:../../textproc/ruby-classifier
DEPENDS+=	${RUBY_PKGPREFIX}-directory-watcher>=1.5.1:../../sysutils/ruby-directory-watcher
DEPENDS+=	${RUBY_PKGPREFIX}-maruku>=0.5<1:../../textproc/ruby-maruku
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=0.14<1:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-pygments.rb>=0.5<0.6:../../www/ruby-pygments.rb
DEPENDS+=	${RUBY_PKGPREFIX}-commander>=4.1.3<4.2:../../misc/ruby-commander
DEPENDS+=	${RUBY_PKGPREFIX}-safe_yaml>=0.7.0:../../textproc/ruby-safe_yaml
DEPENDS+=	${RUBY_PKGPREFIX}-colorator>=0.1<1:../../misc/ruby-colorator
DEPENDS+=	${RUBY_PKGPREFIX}-redcarpet>=3.0.0:../../textproc/ruby-redcarpet

RUBY_VERSION_SUPPORTED=	200 193 21

OVERRIDE_GEMSPEC= directory_watcher>=1.5.1 safe_yaml>=0.9.5 redcarpet>=3.0.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

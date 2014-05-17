# $NetBSD: Makefile,v 1.3 2014/05/17 16:10:49 wiz Exp $

DISTNAME=	pygments.rb-0.5.2
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/tmm1/pygments.rb
COMMENT=	Pygments wrapper for ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-posix-spawn>=0.3.6<0.4:../../devel/ruby-posix-spawn
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.1.0<1.2:../../textproc/ruby-yajl

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2015/06/11 16:41:46 taca Exp $

DISTNAME=	pygments.rb-0.6.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/tmm1/pygments.rb
COMMENT=	Pygments wrapper for ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-posix-spawn>=0.3.6<0.4:../../devel/ruby-posix-spawn
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.2.0<1.3:../../textproc/ruby-yajl

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

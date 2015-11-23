# $NetBSD: Makefile,v 1.7 2015/11/23 12:16:32 wiz Exp $

DISTNAME=	pygments.rb-0.6.3
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/tmm1/pygments.rb
COMMENT=	Pygments wrapper for ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-posix-spawn>=0.3.6<0.4:../../devel/ruby-posix-spawn
DEPENDS+=	${RUBY_PKGPREFIX}-yajl>=1.2.0<1.3:../../textproc/ruby-yajl

REPLACE_PYTHON=	lib/pygments/mentos.py

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/pygments/popen.rb
SUBST_SED.path+=	-e 's|@PYTHON@|python${PYVERSSUFFIX}|'
SUBST_MESSAGE.path=	Fixing Python's path.

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # as of 0.6.3

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

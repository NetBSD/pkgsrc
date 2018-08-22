# $NetBSD: Makefile,v 1.27 2018/08/22 09:47:23 wiz Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGREVISION=		9

DEPENDS+=${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-clearsilver

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

.include "../../mk/bsd.pkg.mk"

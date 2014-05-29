# $NetBSD: Makefile,v 1.20 2014/05/29 23:37:56 wiz Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGREVISION=		6

DEPENDS+=${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-clearsilver

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

.include "../../mk/bsd.pkg.mk"

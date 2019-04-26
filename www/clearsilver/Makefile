# $NetBSD: Makefile,v 1.29 2019/04/26 13:14:19 maya Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGREVISION=		10

DEPENDS+=${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-clearsilver

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.14 2010/02/10 19:17:47 joerg Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGREVISION=		2

DEPENDS+=${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

.include "../../mk/bsd.pkg.mk"

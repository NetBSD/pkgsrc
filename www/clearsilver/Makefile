# $NetBSD: Makefile,v 1.15 2012/03/15 11:53:43 obache Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGREVISION=		3

DEPENDS+=${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

.include "../../mk/bsd.pkg.mk"

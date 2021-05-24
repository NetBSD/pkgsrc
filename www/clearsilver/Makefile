# $NetBSD: Makefile,v 1.35 2021/05/24 19:55:12 wiz Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGREVISION=		14

DEPENDS+=	${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=	${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=	${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

PYTHON_VERSIONS_ACCEPTED=	27 # py-clearsilver

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

.include "../../mk/bsd.pkg.mk"

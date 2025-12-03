# $NetBSD: Makefile,v 1.31 2025/12/03 12:04:03 adam Exp $

DISTNAME=	genshi-0.7.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# i18n
DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel

# "error: 'for' loop initial declarations are only allowed in C99 mode"
FORCE_C_STD=	c99

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

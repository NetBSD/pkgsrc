# $NetBSD: Makefile,v 1.30 2025/04/13 11:01:04 wiz Exp $

DISTNAME=	Genshi-0.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# "error: 'for' loop initial declarations are only allowed in C99 mode"
FORCE_C_STD=	c99

WHEEL_NAME=	${DISTNAME:S/G/g/}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

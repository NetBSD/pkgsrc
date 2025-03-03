# $NetBSD: Makefile,v 1.29 2025/03/03 07:00:55 wiz Exp $

DISTNAME=	Genshi-0.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# "error: 'for' loop initial declarations are only allowed in C99 mode"
FORCE_C_STD=	c99

WHEEL_NAME=	${DISTNAME:S/G/g/}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

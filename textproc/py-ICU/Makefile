# $NetBSD: Makefile,v 1.30 2024/05/29 17:51:10 adam Exp $

DISTNAME=	PyICU-2.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyICU/ICU/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyICU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.pyicu.org/main/pyicu
COMMENT=	Python extension wrapping the ICU C++ libraries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:tl}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

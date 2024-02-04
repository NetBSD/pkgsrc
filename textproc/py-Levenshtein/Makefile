# $NetBSD: Makefile,v 1.15 2024/02/04 18:47:53 adam Exp $

DISTNAME=	Levenshtein-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Levenshtein/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/Levenshtein
COMMENT=	Python extension for computing string edit distances
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0.13.0:../../devel/py-scikit-build
DEPENDS+=	${PYPKGPREFIX}-rapidfuzz>=3.1.0:../../textproc/py-rapidfuzz

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2023/05/15 21:23:53 gutteridge Exp $

DISTNAME=	Levenshtein-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Levenshtein/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/Levenshtein
COMMENT=	Python extension for computing string edit distances
LICENSE=	gnu-gpl-v2

# Needed for cmake installation of objects, when invoked via cmake/build.mk.
INSTALL_DIRS=	${PYSITELIB}

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0.13.0:../../devel/py-scikit-build
DEPENDS+=	${PYPKGPREFIX}-rapidfuzz>=2.3.0:../../textproc/py-rapidfuzz

USE_LANGUAGES=	c c++

GCC_REQD+=	7 # C++17

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/cmake/build.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

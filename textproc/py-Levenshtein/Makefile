# $NetBSD: Makefile,v 1.18 2024/10/13 17:59:17 wiz Exp $

DISTNAME=	levenshtein-0.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/l/L/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/levenshtein/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/Levenshtein
COMMENT=	Python extension for computing string edit distances
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	cmake>=3.15:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0:../../devel/py-scikit-build-core
DEPENDS+=	${PYPKGPREFIX}-rapidfuzz>=3.8.0:../../textproc/py-rapidfuzz

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/Levenshtein/CMakeLists.txt.orig

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2023/06/06 09:39:09 wiz Exp $

DISTNAME=	rapidfuzz-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rapidfuzz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/RapidFuzz
COMMENT=	Rapid fuzzy string matching
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0.17.0:../../devel/py-scikit-build
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1:../../devel/py-test
# optional dependency, but not optional for testing
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	27

PLIST_SUBST+=	PYTHON_VERSION=${PYTHON_VERSION}

USE_LANGUAGES=	c c++

# https://github.com/maxbachmann/RapidFuzz/issues/330
SUBST_CLASSES+=		isnan
SUBST_SED.isnan=	-e 's/isnan/std::isnan/'
SUBST_FILES.isnan+=	src/rapidfuzz/distance/metrics_cpp.cxx
SUBST_FILES.isnan+=	src/rapidfuzz/distance/metrics_cpp.pyx
SUBST_FILES.isnan+=	src/rapidfuzz/distance/metrics_cpp_avx2.cxx
SUBST_FILES.isnan+=	src/rapidfuzz/fuzz_cpp.cxx
SUBST_FILES.isnan+=	src/rapidfuzz/fuzz_cpp.pyx
SUBST_FILES.isnan+=	src/rapidfuzz/fuzz_cpp_avx2.cxx
SUBST_FILES.isnan+=	src/rapidfuzz/process_cpp_impl.cxx
SUBST_FILES.isnan+=	src/rapidfuzz/process_cpp_impl.pyx
SUBST_MESSAGE.isnan=	Fixing isnan issue.
SUBST_STAGE.isnan=	post-extract

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

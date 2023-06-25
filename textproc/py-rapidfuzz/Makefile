# $NetBSD: Makefile,v 1.9 2023/06/25 21:23:10 wiz Exp $

DISTNAME=	rapidfuzz-3.1.1
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

PLIST_SUBST+=	PYTHON_VERSION=${_PYTHON_VERSION}
PLIST_VARS+=	avx2
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "amd64"
PLIST.avx2=	yes
.endif

USE_LANGUAGES=	c c++17
GCC_REQD+=	10

BUILDLINK_TRANSFORM.SunOS+=	rm:-fno-fat-lto-objects

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2023/11/07 09:14:23 wiz Exp $

DISTNAME=	rapidfuzz-3.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rapidfuzz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/RapidFuzz
COMMENT=	Rapid fuzzy string matching
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0.17.0:../../devel/py-scikit-build
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1:../../devel/py-test
# optional dependency, but not optional for testing
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

PLIST_SUBST+=	PYTHON_VERSION=${_PYTHON_VERSION}
PLIST_VARS+=	avx2
# Only x86_64 is guaranteed to have avx2; while some i386 CPUs do, our
# build target does not.
.if ${MACHINE_ARCH} == "x86_64"
PLIST.avx2=	yes
.endif

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
GCC_REQD+=		10

BUILDLINK_TRANSFORM.SunOS+=	rm:-fno-fat-lto-objects

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

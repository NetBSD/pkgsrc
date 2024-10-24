# $NetBSD: Makefile,v 1.32 2024/10/24 17:27:27 adam Exp $

DISTNAME=	rapidfuzz-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rapidfuzz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/RapidFuzz
COMMENT=	Rapid fuzzy string matching
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.10.7:../../devel/py-scikit-build-core
# optional dependency, but not optional for testing
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis

PLIST_SUBST+=	PYTHON_VERSION=${_PYTHON_VERSION}
PLIST_VARS+=	avx2
PLIST_VARS+=	sse2
# x86_64 may use avx2, i386 may use avx2 or sse2
# docs say it'll build them in any case and then autodetect at runtime
# whether the system supports it (using _feature_detector_cpp.so)
.if ${MACHINE_ARCH} == "x86_64"
PLIST.avx2=	yes
.else
.  if ${MACHINE_ARCH} == "i386"
PLIST.avx2=	yes
PLIST.sse2=	yes
.  endif
.endif

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
GCC_REQD+=		10

BUILDLINK_TRANSFORM.SunOS+=	rm:-fno-fat-lto-objects

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/rapidfuzz/CMakeLists.txt.orig \
	      ${DESTDIR}${PREFIX}/${PYSITELIB}/rapidfuzz/distance/CMakeLists.txt.orig

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

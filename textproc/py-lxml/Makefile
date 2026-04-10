# $NetBSD: Makefile,v 1.127 2026/04/10 04:00:33 adam Exp $

DISTNAME=	lxml-6.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.11:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.7:../../textproc/py-cssselect

USE_CC_FEATURES=	c99

# pycore_frame.h:134:5: error:
# 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		gnu99

# as of 5.3.0, tests only work if lxml is built in-tree
# pkgsrc defaults to out-of-src-tree though
#
# to manually test:
# make patch
# cd ${WRKSRC}
# python3.13 setup.py build_ext -i
# python3.13 test.py

# as of 6.0.0 this gives:
# Ran 2003 tests in 5.956s

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9.12
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.34
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

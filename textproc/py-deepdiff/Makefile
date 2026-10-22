# $NetBSD: Makefile,v 1.31 2026/10/22 07:42:15 adam Exp $

DISTNAME=	deepdiff-9.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-cachebox>=5.2:../../devel/py-cachebox
DEPENDS+=	${PYPKGPREFIX}-orderly-set>=5.5.0:../../devel/py-orderly-set
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=8.3.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.3:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-dotenv>=1.2.2:../../devel/py-dotenv
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=2.2.0:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas>=2.2.0:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic>=0:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=5.2.3:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1.0:../../devel/py-test-cov
# unpackaged: uuid6

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	deep

REPLACE_PYTHON+=	deepdiff/diff.py

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

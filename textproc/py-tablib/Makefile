# $NetBSD: Makefile,v 1.7 2023/01/18 11:33:46 adam Exp $

DISTNAME=	tablib-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tablib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tablib.readthedocs.io/
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# all without pandas
DEPENDS+=	${PYPKGPREFIX}-markuppy-[0-9]*:../../textproc/py-markuppy
DEPENDS+=	${PYPKGPREFIX}-odfpy-[0-9]*:../../textproc/py-odfpy
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=2.6.0:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-tabulate-[0-9]*:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-xlrd-[0-9]*:../../textproc/py-xlrd
DEPENDS+=	${PYPKGPREFIX}-xlwt-[0-9]*:../../textproc/py-xlwt
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

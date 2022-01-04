# $NetBSD: Makefile,v 1.5 2022/01/04 20:55:07 wiz Exp $

DISTNAME=	tablib-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tablib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tablib.readthedocs.io/
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-odfpy-[0-9]*:../../textproc/py-odfpy
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=2.6.0:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-tabulate-[0-9]*:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-xlrd-[0-9]*:../../textproc/py-xlrd
DEPENDS+=	${PYPKGPREFIX}-xlwt-[0-9]*:../../textproc/py-xlwt
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# requires py-markuppy
#do-test:
#	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests/test_tablib.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

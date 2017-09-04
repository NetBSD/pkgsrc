# $NetBSD: Makefile,v 1.1 2017/09/04 19:46:26 adam Exp $

DISTNAME=	tablib-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tablib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-tablib.org/
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-odfpy-[0-9]*:../../textproc/py-odfpy
DEPENDS+=	${PYPKGPREFIX}-openpyxl-[0-9]*:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-unicodecsv-[0-9]*:../../databases/py-unicodecsv
DEPENDS+=	${PYPKGPREFIX}-xlrd-[0-9]*:../../textproc/py-xlrd
DEPENDS+=	${PYPKGPREFIX}-xlwt-[0-9]*:../../textproc/py-xlwt
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} test_tablib.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

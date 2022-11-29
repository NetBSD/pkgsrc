# $NetBSD: Makefile,v 1.28 2022/11/29 10:20:57 adam Exp $

DISTNAME=	openpyxl-3.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openpyxl/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://openpyxl.readthedocs.io/
COMMENT=	Python library to read/write Excel xlsx/xlsm files
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-jdcal-[0-9]*:../../time/py-jdcal
DEPENDS+=	${PYPKGPREFIX}-et_xmlfile-[0-9]*:../../textproc/py-et_xmlfile

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.25 2019/08/20 07:10:58 adam Exp $

DISTNAME=	openpyxl-2.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openpyxl/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://openpyxl.readthedocs.io/
COMMENT=	Python library to read/write Excel 2007 xlsx/xlsm files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jdcal-[0-9]*:../../time/py-jdcal
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

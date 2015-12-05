# $NetBSD: Makefile,v 1.4 2015/12/05 21:26:02 adam Exp $

DISTNAME=	xlwt-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/x/xlwt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python-excel.org/
COMMENT=	Writing data and formatting information from Excel files
LICENSE=	original-bsd

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	xlwt/Formatting.py
REPLACE_PYTHON+=	xlwt/examples/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.7.5

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

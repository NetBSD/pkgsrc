# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:22 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.7.5

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

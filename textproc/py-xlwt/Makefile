# $NetBSD: Makefile,v 1.7 2017/01/01 14:44:01 wiz Exp $

DISTNAME=	xlwt-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xlwt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python-excel.org/
COMMENT=	Writing data and formatting information from Excel files
LICENSE=	original-bsd

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	xlwt/Formatting.py
REPLACE_PYTHON+=	xlwt/examples/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.7.5

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

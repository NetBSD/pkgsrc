# $NetBSD: Makefile,v 1.6 2016/07/09 13:04:11 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.7.5

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

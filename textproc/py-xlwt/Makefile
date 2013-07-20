# $NetBSD: Makefile,v 1.1 2013/07/20 07:40:11 richard Exp $

DISTNAME=		xlwt-0.7.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/x/xlwt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.python-excel.org/
COMMENT=		Writing data and formatting information from Excel files
LICENSE=		original-bsd

USE_LANGUAGES=	#none

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	xlwt/Formatting.py
REPLACE_FILES.python+=	xlwt/examples/*.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

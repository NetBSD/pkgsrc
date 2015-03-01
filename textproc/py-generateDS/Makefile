# $NetBSD: Makefile,v 1.2 2015/03/01 20:03:27 joerg Exp $
#

DISTNAME=	generateDS-2.14a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
EGG_NAME=	generateDS-${PKGVERSION}0
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/g/generateDS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.davekuhlman.org/generateDS.html
COMMENT=	Python XML data binding library

LICENSE=	mit

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
# TODO: explain
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-xml

REPLACE_PYTHON=	generateDS.py libgenerateDS/gui/*.py libgenerateDS/*.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
# TODO: Explain why this is commented out and present.
#.include "../../textproc/py-xml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

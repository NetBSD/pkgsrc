# $NetBSD: Makefile,v 1.6 2005/01/23 20:41:49 recht Exp $
#

DISTNAME=	csv-1.0
PKGNAME=	${PYPKGPREFIX}-csv-1.0
CATEGORIES=	textproc python
MASTER_SITES=	http://www.object-craft.com.au/projects/csv/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.object-craft.com.au/projects/csv/
COMMENT=	CSV reading module for Python

USE_BUILDLINK3=	YES

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

PYTHON_VERSIONS_ACCEPTED=	22 21 20

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2003/09/14 18:13:49 recht Exp $
#

DISTNAME=	csv-1.0
PKGNAME=	${PYPKGPREFIX}-csv-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.object-craft.com.au/projects/csv/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.object-craft.com.au/projects/csv/
COMMENT=	CSV reading module for Python

USE_BUILDLINK2=	YES

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

PYTHON_VERSIONS_ACCEPTED=	22 22pth 21 21pth 20

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

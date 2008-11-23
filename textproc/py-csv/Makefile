# $NetBSD: Makefile,v 1.10 2008/11/23 23:35:06 snj Exp $
#

DISTNAME=	csv-1.0
PKGNAME=	${PYPKGPREFIX}-csv-1.0
CATEGORIES=	textproc python
MASTER_SITES=	http://www.object-craft.com.au/projects/csv/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.object-craft.com.au/projects/csv/
COMMENT=	CSV reading module for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

PYTHON_VERSIONS_ACCEPTED=	21 # included in python>=2.3

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

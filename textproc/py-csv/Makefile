# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:52 joerg Exp $
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

PYTHON_VERSIONS_ACCEPTED=	21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

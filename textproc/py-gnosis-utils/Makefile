# $NetBSD: Makefile,v 1.1.1.1 2004/03/06 18:54:12 recht Exp $
#

DISTNAME=	Gnosis_Utils-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML

USE_BUILDLINK3=	yes

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

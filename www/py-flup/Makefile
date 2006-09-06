# $NetBSD: Makefile,v 1.2 2006/09/06 10:59:30 joerg Exp $
#

DISTNAME=	flup-r2030
PKGNAME=	${PYPKGPREFIX}-flup-2030
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.saddi.com/software/flup/dist/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.saddi.com/software/flup/
COMMENT=	WSGI support modules

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py24-setuptools

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

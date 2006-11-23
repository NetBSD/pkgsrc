# $NetBSD: Makefile,v 1.2.2.1 2006/11/23 09:41:31 ghen Exp $
#

DISTNAME=	flup-r2030
PKGNAME=	${PYPKGPREFIX}-flup-2030
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://www.saddi.com/software/flup/dist/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.saddi.com/software/flup/
COMMENT=	WSGI support modules

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c1nb1:../../devel/py24-setuptools

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24

FILES_SUBST+=	PY_MANAGE_EGGS=${PREFIX}/bin/${PYPKGPREFIX}-manage-eggs
FILES_SUBST+=	FLUPEGG=${PREFIX}/${PYSITELIB}/flup-0.5-py2.4.egg

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2007/02/22 19:01:27 wiz Exp $
#

DISTNAME=	flup-r2030
PKGNAME=	${PYPKGPREFIX}-flup-2030
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://www.saddi.com/software/flup/dist/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://trac.saddi.com/flup
COMMENT=	WSGI support modules

PKG_DESTDIR_SUPPORT=	# empty

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c1nb1:../../devel/py-setuptools
CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/easy-install.pth

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24

FILES_SUBST+=	PY_MANAGE_EGGS=${PREFIX}/bin/${PYPKGPREFIX}-manage-eggs
FILES_SUBST+=	FLUPEGG=${PREFIX}/${PYSITELIB}/flup-0.5-py2.4.egg

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

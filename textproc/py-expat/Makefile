# $NetBSD: Makefile,v 1.1.1.1 2002/10/16 16:45:56 tsarna Exp $
#

PKGNAME=	${PYPKGPREFIX}-expat-0
CATEGORIES=	textproc

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Python interface to expat

EXTRACT_ELEMENTS=       ${PYSUBDIR}/Modules/pyexpat.c

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

USE_BUILDLINK2= yes

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../textproc/expat/buildlink2.mk"
.include "../../lang/python/srcdist.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

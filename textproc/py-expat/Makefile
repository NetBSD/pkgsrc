# $NetBSD: Makefile,v 1.5 2004/04/25 04:59:40 snj Exp $
#

PKGNAME=	${PYPKGPREFIX}-expat-0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Python interface to expat

EXTRACT_ELEMENTS=       ${PYSUBDIR}/Modules/pyexpat.c

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

USE_BUILDLINK3= yes

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"

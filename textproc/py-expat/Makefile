# $NetBSD: Makefile,v 1.16 2011/12/03 00:02:16 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-expat-0
PKGREVISION=	5
CATEGORIES=	textproc python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Python interface to expat

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/pyexpat.c

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PY_SETUP_SUBST+= EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+= EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

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

# $NetBSD: Makefile,v 1.10 2014/01/25 10:30:23 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-cElementTree-${PY_DISTVERSION}
CATEGORIES=	textproc python

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.effbot.org/zone/celementtree.htm
COMMENT=	C implementation of Python ElementTree API

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_elementtree.c

USE_TOOLS+=	patch

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
	${PATCH} --batch <$$f || ${TRUE}; \
	done)

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.12 2002/10/09 14:35:38 wiz Exp $
#

DISTNAME=	wxPython-2.2.2
PKGNAME=	${PYPKGPREFIX}-wxWindows-2.2.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	wxPython: Python bindings for wxWindows

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

PYTHON_VERSIONS_ACCEPTED=	20 # distutils problem with 21 and 22
PYDISTUTILSPKG=	yes
PYSETUPBUILDARGS=	BUILD_GLCANVAS=0
PYBINMODULE=	yes

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}/${PYSITELIB}/wxPython; \
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py . ; \
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py . )
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/wxPython \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/wxPython \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

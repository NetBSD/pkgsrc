# $NetBSD: Makefile,v 1.37 2006/05/26 19:56:16 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-Tk-0
PKGREVISION=	4
CATEGORIES=	x11 python

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/topics/tkinter/
COMMENT=	Tkinter -- Python interface to Tcl/Tk


EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_tkinter.c \
			${PYSUBDIR}/Modules/tkappinit.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST+= BLPREFIX=${LOCALBASE}
PY_SETUP_SUBST+= TCLRTPREFIX=${BUILDLINK_PREFIX.tcl}
PY_SETUP_SUBST+= TKRTPREFIX=${BUILDLINK_PREFIX.tk}
PY_SETUP_SUBST+= X11PREFIX=${X11BASE}
PY_SETUP_SUBST+= X11RTPREFIX=${X11BASE}

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21 20 15

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

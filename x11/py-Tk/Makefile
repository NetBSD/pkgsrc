# $NetBSD: Makefile,v 1.22 2002/09/23 22:55:30 jlam Exp $
#

PKGNAME=	${PYPKGPREFIX}-Tk-0
CATEGORIES=	x11

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/topics/tkinter/
COMMENT=	Tkinter -- Python interface to Tcl/Tk

USE_BUILDLINK2=	yes
USE_X11=	yes

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
PLIST_SUBST+= PYLIB=${PYLIB}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

# this is needed by graphics/sketch
post-install:
	${SED}	-e "s|@LOCALBASE@|${LOCALBASE}|g" \
		-e "s|@X11BASE@|${X11BASE}|g" \
		<${FILESDIR}/Setup.in >${PREFIX}/${PYLIB}/config/Setup.tk

.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

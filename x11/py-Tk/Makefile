# $NetBSD: Makefile,v 1.19 2002/01/28 17:34:29 drochner Exp $
#

PKGNAME=	${PYPKGPREFIX}-Tk-0
CATEGORIES=	x11

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/topics/tkinter/
COMMENT=	Tkinter -- Python interface to Tcl/Tk

DEPENDS+=	tk>=8.3.2:../../x11/tk
EVAL_PREFIX+=	TCLDIR=tcl

USE_X11=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_tkinter.c \
			${PYSUBDIR}/Modules/tkappinit.c
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

PY_SETUP_SUBST+= TCLPREFIX=${TCLDIR}
PY_SETUP_SUBST+= X11PREFIX=${X11BASE}
PLIST_SUBST+= PYLIB=${PYLIB}

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || true; \
	done)

# this is needed by graphics/sketch
post-install:
	${SED} -e "s|@LOCALBASE@|${LOCALBASE}|g" \
		-e "s|@X11BASE@|${X11BASE}|g" \
		<${FILESDIR}/Setup.in >${PREFIX}/${PYLIB}/config/Setup.tk

.include "../../lang/python/extension.buildlink.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"

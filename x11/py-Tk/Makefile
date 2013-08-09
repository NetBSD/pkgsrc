# $NetBSD: Makefile,v 1.57 2013/08/09 15:18:58 adam Exp $

PKGNAME=	${PYPKGPREFIX}-Tk-${PY_DISTVERSION}
PKGREVISION=	3
CATEGORIES=	x11 python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.python.org/moin/TkInter
COMMENT=	Tkinter -- Python interface to Tcl/Tk
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCLUDE_3X=	yes

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_tkinter.c \
			${PYSUBDIR}/Modules/tkappinit.c
PYDISTUTILSPKG=		yes
PY_PATCHPLIST=		yes
PY_SETUP_SUBST+=	BLPREFIX=${LOCALBASE}
PY_SETUP_SUBST+=	TCLRTPREFIX=${BUILDLINK_PREFIX.tcl}
PY_SETUP_SUBST+=	TKRTPREFIX=${BUILDLINK_PREFIX.tk}
PY_SETUP_SUBST+=	X11PREFIX=${X11BASE}
PY_SETUP_SUBST+=	X11RTPREFIX=${X11BASE}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PY_SETUP_SUBST+=	X11LIB=
.else
PY_SETUP_SUBST+=	X11LIB=\'X11\'
.endif

.include "../../lang/python/extension.mk"

.if ${_PYTHON_VERSION} >= 27
EXTRACT_ELEMENTS+=	${PYSUBDIR}/Modules/tkinter.h
.endif

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	set -e; cd ${WRKSRC} && for f in ${PATCHDIR}/patch-*; do \
	${PATCH} ${PATCHARGS} --batch <$$f || ${TRUE}; \
	done

.include "../../lang/python/srcdist.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.28 2004/04/24 22:47:00 snj Exp $
#

DISTNAME=	wxPythonSrc-2.4.2.4
PKGNAME=	${PYPKGPREFIX}-wxWindows-2.4.2.4
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	wxPython: Python bindings for wxWindows

WRKSRC=		${WRKDIR}/wxPythonSrc-2.4.2.4/wxPython
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

# we depend on glib which pulls in threads
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth
BUILDLINK_DEPENDS.python21-pth=	python21-pth>=2.1.3nb3
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2

.include "../../mk/bsd.prefs.mk"

.if empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
WXARG=	WXPORT=gtk2
.endif

PYDISTUTILSPKG=	yes
# no GL to limit dependencies
# OGL doesn't build with egcs-1.1.2
# no scripts to avoid conflicts
PYSETUPBUILDARGS=	BUILD_GLCANVAS=0 BUILD_OGL=0 NO_SCRIPTS=1 ${WXARG}
PYSETUPINSTALLARGS=	BUILD_GLCANVAS=0 BUILD_OGL=0 NO_SCRIPTS=1 ${WXARG}
PYBINMODULE=	yes

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

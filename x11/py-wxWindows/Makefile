# $NetBSD: Makefile,v 1.19 2003/09/14 16:43:57 recht Exp $
#

DISTNAME=	wxPythonSrc-2.4.1.2
PKGNAME=	${PYPKGPREFIX}-wxWindows-2.4.1.2
WRKSRC=		${WRKDIR}/wxPythonSrc-2.4.1.2/wxPython
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	wxPython: Python bindings for wxWindows

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

# we depend on glib which pulls in threads
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth
BUILDLINK_DEPENDS.python21-pth=	python21-pth>=2.1.3nb3
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2nb2
BUILDLINK_DEPENDS.wxGTK=	wxGTK>=2.4.1nb1

PYDISTUTILSPKG=	yes
# no GL to limit dependencies
# OGL doesn't build with egcs-1.1.2
# no scripts to avoid conflicts
PYSETUPBUILDARGS=	BUILD_GLCANVAS=0 BUILD_OGL=0 NO_SCRIPTS=1
PYSETUPINSTALLARGS=	BUILD_GLCANVAS=0 BUILD_OGL=0 NO_SCRIPTS=1
PYBINMODULE=	yes

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

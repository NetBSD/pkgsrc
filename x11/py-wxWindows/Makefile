# $NetBSD: Makefile,v 1.32 2004/10/03 00:18:37 tv Exp $
#

DISTNAME=	wxPythonSrc-2.4.2.4
PKGNAME=	${PYPKGPREFIX}-wxWindows-2.4.2.4
PKGREVISION=	6
CATEGORIES=	x11 python
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
# no scripts to avoid conflicts
PYSETUPBUILDARGS=	NO_SCRIPTS=1 ${WXARG}
PYSETUPINSTALLARGS=	NO_SCRIPTS=1 ${WXARG}
PYBINMODULE=	yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.8 2005/08/07 11:31:32 wiz Exp $
#

DISTNAME=	wxPythonSrc-2.4.2.4
PKGNAME=	${PYPKGPREFIX}-wxWidgets-2.4.2.4
PKGREVISION=	7
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	wxPython: Python bindings for wxWidgets

WRKSRC=		${WRKDIR}/wxPythonSrc-2.4.2.4/wxPython
USE_TOOLS+=	gmake

# previous name of the package
CONFLICTS+=	${PYPKGPREFIX}-wxWindows-[0-9]*

# we depend on glib which pulls in threads
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
BUILDLINK_DEPENDS.python21=	python21>=2.1.3nb3
BUILDLINK_DEPENDS.python22=	python22>=2.2.2nb2

WXARG=	WXPORT=gtk2 WX_CONFIG=${LOCALBASE}/bin/wx24-config

PYDISTUTILSPKG=	yes
# no scripts to avoid conflicts
PYSETUPBUILDARGS=	NO_SCRIPTS=1 ${WXARG}
PYSETUPINSTALLARGS=	NO_SCRIPTS=1 ${WXARG}
PYBINMODULE=	yes

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

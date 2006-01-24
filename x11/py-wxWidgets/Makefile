# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:59 wiz Exp $
#

DISTNAME=	wxPython-src-2.6.1.0
PKGNAME=	${PYPKGPREFIX}-wxWidgets-2.6.1.0
PKGREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	Python bindings for wxWidgets

WRKSRC=		${WRKDIR}/wxPython-src-2.6.1.0/wxPython
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=	${PYPKGPREFIX}-wxWindows-[0-9]*

PYTHON_VERSIONS_ACCEPTED=	24 23

WXARG=	WXPORT=gtk2 \
	WX_CONFIG=${BUILDLINK_PREFIX.wxGTK}/bin/wx-config \
	CONTRIBS_INC="../contrib/include" \
	BUILD_ANIMATE=0

PYDISTUTILSPKG=	yes
# no scripts to avoid conflicts
PYSETUPBUILDARGS=	NO_SCRIPTS=1 ${WXARG}
PYSETUPINSTALLARGS=	NO_SCRIPTS=1 ${WXARG}
PYBINMODULE=	yes

PLIST_SUBST+=            GTKVER=2

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../x11/wxGTK-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

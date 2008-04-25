# $NetBSD: Makefile,v 1.19 2008/04/25 20:39:14 joerg Exp $
#

DISTNAME=	wxPython-src-2.6.3.3
PKGNAME=	${PYPKGPREFIX}-wxWidgets-2.6.3.3
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	Python bindings for wxWidgets

WRKSRC=		${WRKDIR}/wxPython-src-2.6.3.3/wxPython
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=	${PYPKGPREFIX}-wxWindows-[0-9]*

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
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../x11/wxGTK-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.30 2011/01/13 13:36:15 wiz Exp $
#

VERSION=	2.8.10.1
DISTNAME=	wxPython-src-${VERSION}
PKGNAME=	${PYPKGPREFIX}-wxWidgets-${VERSION}
PKGREVISION=	6
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wxpython.org/
COMMENT=	Python bindings for wxWidgets

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wxPython-src-${VERSION}/wxPython
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=	${PYPKGPREFIX}-wxWindows-[0-9]*

WXARG=	WXPORT=gtk2 UNICODE=1

PYDISTUTILSPKG=	yes
# no scripts to avoid conflicts
#PYSETUPBUILDARGS=	NO_SCRIPTS=1 ${WXARG}
#PYSETUPINSTALLARGS=	NO_SCRIPTS=1 ${WXARG}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

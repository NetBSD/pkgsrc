# $NetBSD: Makefile,v 1.37 2013/01/26 21:36:56 adam Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-modules-${PYQT_VERSION}
PKGREVISION=		10

COMMENT=		Various Python modules for Qt3

INSTALL_DIRS=	qtcanvas qtgl qtnetwork qtsql qttable qtui qtxml

.include "../../x11/py-qt3-base/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

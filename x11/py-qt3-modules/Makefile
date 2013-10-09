# $NetBSD: Makefile,v 1.42 2013/10/09 17:39:03 wiz Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-modules-${PYQT_VERSION}
PKGREVISION=		15

COMMENT=		Various Python modules for Qt3

INSTALL_DIRS=	qtcanvas qtgl qtnetwork qtsql qttable qtui qtxml

.include "../../x11/py-qt3-base/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.35 2012/05/06 18:52:04 dholland Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-modules-${PYQT_VERSION}
PKGREVISION=		9

COMMENT=		Various Python modules for Qt3

INSTALL_DIRS=	qtcanvas qtgl qtnetwork qtsql qttable qtui qtxml

.include "../../x11/py-qt3-base/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

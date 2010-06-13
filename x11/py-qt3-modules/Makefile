# $NetBSD: Makefile,v 1.31 2010/06/13 22:45:50 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-modules-${PYQT_VERSION}
PKGREVISION=		5

COMMENT=		Various Python modules for Qt3

INSTALL_DIRS=	qtcanvas qtgl qtnetwork qtsql qttable qtui qtxml

.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

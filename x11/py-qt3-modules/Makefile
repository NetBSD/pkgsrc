# $NetBSD: Makefile,v 1.23 2006/04/17 13:46:06 wiz Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-modules-${PYQT_VERSION}
PKGREVISION=		3

COMMENT=		Various Python modules for Qt3

INSTALL_DIRS=	${WRKSRC}/qtcanvas ${WRKSRC}/qtgl ${WRKSRC}/qtnetwork
INSTALL_DIRS+=	${WRKSRC}/qtsql ${WRKSRC}/qttable ${WRKSRC}/qtui
INSTALL_DIRS+=	${WRKSRC}/qtxml

.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
